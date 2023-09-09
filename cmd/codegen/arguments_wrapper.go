package main

import "C"
import (
	"fmt"
)

type ArgumentWrapperData struct {
	// go-valid argument type (e.g. string, ImVec2, etc.)
	ArgType GoIdentifier
	// argument deffinition (e.g. arg1, arg1Fin := ...\ndefer arg1Fin())
	ArgDef string
	// This is equivalent of above (VarName will be appropiate here), but it will not define Finalizer (use this if you're not going to use Finalizer)
	ArgDefNoFin string
	// one-line go statement that should be called after calling C function
	// in order to update go value.
	// It is intended to be run in defer statement (and it will be in most cases)
	// so it should be one-line function call OR a call of custom function
	Finalizer string

	// a name of variable of wrapped C type
	VarName string

	NoFin bool
}

type argumentWrapper func(arg ArgDef) ArgumentWrapperData

func getArgWrapper(a *ArgDef, makeFirstArgReceiver, isGetter bool, structNames map[CIdentifier]bool, enumNames map[GoIdentifier]bool) (argDeclaration string, data ArgumentWrapperData, err error) {
	argWrapperMap := map[CIdentifier]argumentWrapper{
		"char":                     simpleW("rune", "C.char"),
		"char[5]":                  simplePtrArrayW(5, "C.char", "rune"),
		"char[16]":                 simplePtrArrayW(16, "C.char", "rune"),
		"char*":                    constCharW,
		"const char*":              constCharW,
		"const char**":             charPtrPtrW,
		"const char* const[]":      charPtrPtrW,
		"unsigned char":            simpleW("uint", "C.uchar"),
		"unsigned char*":           simplePtrW("uint", "C.uchar"),
		"unsigned char**":          uCharPtrW,
		"size_t":                   simpleW("uint64", "C.xulong"),
		"size_t*":                  sizeTPtrW,
		"float":                    simpleW("float32", "C.float"),
		"const float":              simpleW("float32", "C.float"),
		"float*":                   simplePtrW("float32", "C.float"),
		"const float*":             floatArrayW,
		"short":                    simpleW("int16", "C.short"),
		"unsigned short":           simpleW("uint16", "C.ushort"),
		"ImU8":                     simpleW("byte", "C.ImU8"),
		"ImU8*":                    simplePtrW("byte", "C.ImU8"),
		"const ImU8*":              simplePtrSliceW("C.ImU8", "byte"),
		"ImU16":                    simpleW("uint16", "C.ImU16"),
		"ImU16*":                   simplePtrW("uint16", "C.ImU16"),
		"const ImU16*":             simplePtrSliceW("C.ImU16", "uint16"),
		"ImU32":                    simpleW("uint32", "C.ImU32"),
		"ImU32*":                   simplePtrW("uint32", "C.ImU32"),
		"const ImU32*":             simplePtrSliceW("C.ImU32", "uint32"),
		"ImU64":                    simpleW("uint64", "C.ImU64"),
		"ImU64*":                   simplePtrSliceW("C.ImU64", "uint64"),
		"const ImU64*":             uint64ArrayW,
		"ImS8":                     simpleW("int", "C.ImS8"),
		"ImS8*":                    simplePtrSliceW("C.ImS8", "int8"),
		"const ImS8*":              simplePtrSliceW("C.ImS8", "int8"),
		"ImS16":                    simpleW("int", "C.ImS16"),
		"ImS16*":                   simplePtrSliceW("C.ImS16", "int"),
		"const ImS16*":             simplePtrSliceW("C.ImS16", "int"),
		"ImS32":                    simpleW("int", "C.ImS32"),
		"ImS32*":                   simplePtrSliceW("C.ImS32", "int32"),
		"const ImS32*":             simplePtrSliceW("C.ImS32", "int32"),
		"ImS64":                    simpleW("int64", "C.ImS64"),
		"ImS64*":                   simplePtrW("int64", "C.ImS64"),
		"const ImS64*":             int64ArrayW,
		"int":                      simpleW("int32", "C.int"),
		"int*":                     simplePtrW("int32", "C.int"),
		"unsigned int":             simpleW("uint32", "C.uint"),
		"unsigned int*":            simplePtrW("uint32", "C.uint"),
		"double":                   simpleW("float64", "C.double"),
		"double*":                  simplePtrW("float64", "C.double"),
		"const double*":            simplePtrSliceW("C.double", "float64"),
		"bool":                     simpleW("bool", "C.bool"),
		"bool*":                    boolPtrW,
		"int[2]":                   simplePtrArrayW(2, "C.int", "int32"),
		"int[3]":                   simplePtrArrayW(3, "C.int", "int32"),
		"int[4]":                   simplePtrArrayW(4, "C.int", "int32"),
		"float[2]":                 simplePtrArrayW(2, "C.float", "float32"),
		"float[3]":                 simplePtrArrayW(3, "C.float", "float32"),
		"float[4]":                 simplePtrArrayW(4, "C.float", "float32"),
		"ImWchar":                  simpleW("Wchar", "C.ImWchar"),
		"ImWchar*":                 simpleW("(*Wchar)", "(*C.ImWchar)"),
		"const ImWchar*":           simpleW("(*Wchar)", "(*C.ImWchar)"),
		"ImWchar16":                simpleW("uint16", "C.ImWchar16"),
		"ImGuiID":                  simpleW("ID", "C.ImGuiID"),
		"ImGuiID*":                 simplePtrW("ID", "C.ImGuiID"),
		"ImTextureID":              simpleW("TextureID", "C.ImTextureID"),
		"ImDrawIdx":                simpleW("DrawIdx", "C.ImDrawIdx"),
		"ImDrawIdx*":               simplePtrW("DrawIdx", "C.ImDrawIdx"),
		"ImGuiTableColumnIdx":      simpleW("TableColumnIdx", "C.ImGuiTableColumnIdx"),
		"ImGuiTableDrawChannelIdx": simpleW("TableDrawChannelIdx", "C.ImGuiTableDrawChannelIdx"),
		"ImGuiKeyChord":            simpleW("KeyChord", "C.ImGuiKeyChord"),
		"void*":                    simpleW("unsafe.Pointer", ""),
		"const void*":              simpleW("unsafe.Pointer", ""),
		"const ImVec2":             wrappableW("Vec2"),
		"const ImVec2*":            wrappablePtrW("*Vec2", "C.ImVec2"),
		"ImVec2":                   wrappableW("Vec2"),
		"ImVec2*":                  wrappablePtrW("*Vec2", "C.ImVec2"),
		"ImVec2[2]":                wrappablePtrArrayW(2, "C.ImVec2", "Vec2"),
		"const ImVec4":             wrappableW("Vec4"),
		"const ImVec4*":            wrappablePtrW("*Vec4", "C.ImVec4"),
		"ImVec4":                   wrappableW("Vec4"),
		"ImVec4*":                  wrappablePtrW("*Vec4", "C.ImVec4"),
		"ImColor*":                 wrappablePtrW("*Color", "C.ImColor"),
		"ImRect":                   wrappableW("Rect"),
		"const ImRect":             wrappableW("Rect"),
		"ImRect*":                  wrappablePtrW("*Rect", "C.ImRect"),
		"const ImRect*":            wrappablePtrW("*Rect", "C.ImRect"),
		"ImPlotPoint":              wrappableW("PlotPoint"),
		"const ImPlotPoint":        wrappableW("PlotPoint"),
		"ImPlotPoint*":             wrappablePtrW("*PlotPoint", "C.ImPlotPoint"),
		"ImPlotTime":               wrappableW("PlotTime"),
		"const ImPlotTime":         wrappableW("PlotTime"),
		"ImPlotTime*":              wrappablePtrW("*PlotTime", "C.ImPlotTime"),
		"const ImPlotTime*":        wrappablePtrW("*PlotTime", "C.ImPlotTime"),
	}

	if a.Name == "type" || a.Name == "range" {
		a.Name += "Arg"
	}

	if makeFirstArgReceiver {
		return "", ArgumentWrapperData{}, nil
	}

	if isGetter {
		argDeclaration = fmt.Sprintf("%s %s", a.Name, a.Type.renameGoIdentifier())
		data = ArgumentWrapperData{
			ArgDef:      fmt.Sprintf("%[1]sArg, %[1]sFin := %[1]s.handle()", a.Name),
			ArgDefNoFin: fmt.Sprintf("%[1]sArg, _ := %[1]s.handle()", a.Name),
			VarName:     fmt.Sprintf("%sArg", a.Name),
			Finalizer:   fmt.Sprintf("%sFin()", a.Name),
			NoFin:       a.RemoveFinalizer,
		}

		return
	}

	if v, ok := argWrapperMap[a.Type]; ok {
		arg := v(*a)
		data = arg
		data.NoFin = a.RemoveFinalizer

		argDeclaration = fmt.Sprintf("%s %s", a.Name, arg.ArgType)

		return argDeclaration, data, nil
	}

	if goEnumName := a.Type; isEnum(goEnumName, enumNames) {
		argDeclaration = fmt.Sprintf("%s %s", a.Name, goEnumName.renameGoIdentifier())
		data = ArgumentWrapperData{
			ArgType: a.Type.renameEnum(),
			VarName: fmt.Sprintf("C.%s(%s)", a.Type, a.Name),
		}

		return
	}

	if HasPrefix(a.Type, "ImVector_") &&
		!(HasSuffix(a.Type, "*") || HasSuffix(a.Type, "]")) {
		pureType := TrimPrefix(a.Type, "ImVector_") + "*"
		dataName := a.Name + "Data"
		_, w, err := getArgWrapper(&ArgDef{
			Name: dataName,
			Type: pureType,
		}, false, false, structNames, enumNames)

		if err != nil {
			return "", ArgumentWrapperData{}, fmt.Errorf("creating vector wrapper %w", err)
		}

		data = ArgumentWrapperData{
			VarName: string("*" + a.Name + "VecArg"),
			ArgType: GoIdentifier(fmt.Sprintf("Vector[%s]", w.ArgType)),
			ArgDef: fmt.Sprintf(`%[5]s := %[2]s.Data
%[1]s
%[2]sVecArg := new(C.%[3]s)
%[2]sVecArg.Size = C.int(%[2]s.Size)
%[2]sVecArg.Capacity = C.int(%[2]s.Capacity)
%[2]sVecArg.Data = %[4]s
`, w.ArgDef, a.Name, a.Type, w.VarName, dataName),
			ArgDefNoFin: fmt.Sprintf(`%[5]s := %[2]s.Data
%[1]s
%[2]sVecArg := new(C.%[3]s)
%[2]sVecArg.Size = C.int(%[2]s.Size)
%[2]sVecArg.Capacity = C.int(%[2]s.Capacity)
%[2]sVecArg.Data = %[4]s
`, w.ArgDefNoFin, a.Name, a.Type, w.VarName, dataName),
			Finalizer: w.Finalizer,
			NoFin:     a.RemoveFinalizer,
		}

		argDeclaration = fmt.Sprintf("%s %s", a.Name, data.ArgType)

		return argDeclaration, data, nil
	}

	pureType := TrimPrefix(a.Type, "const ")
	isPointer := false
	if HasSuffix(a.Type, "*") {
		pureType = TrimSuffix(pureType, "*")
		isPointer = true
	}

	if structNames[pureType] {
		w := ArgumentWrapperData{
			ArgType:   pureType.renameGoIdentifier(),
			VarName:   fmt.Sprintf("%sArg", a.Name),
			Finalizer: fmt.Sprintf("%sFin()", a.Name),
			NoFin:     a.RemoveFinalizer,
		}

		fn := ""
		if isPointer {
			w.ArgType = "*" + w.ArgType
			fn = "handle"
		} else {
			fn = "c"
		}

		w.ArgDef = fmt.Sprintf("%[1]sArg, %[1]sFin := %[1]s.%[2]s()", a.Name, fn)
		w.ArgDefNoFin = fmt.Sprintf("%[1]sArg, _ := %[1]s.%[2]s()", a.Name, fn)

		data = w

		argDeclaration = fmt.Sprintf("%s %s", a.Name, data.ArgType)

		return
	}

	return "", ArgumentWrapperData{}, fmt.Errorf("unknown argument type \"%s\"", a.Type)
}

func constCharW(arg ArgDef) ArgumentWrapperData {
	return ArgumentWrapperData{
		ArgType:     "string",
		VarName:     fmt.Sprintf("%sArg", arg.Name),
		ArgDef:      fmt.Sprintf("%[1]sArg, %[1]sFin := WrapString(%[1]s)", arg.Name),
		ArgDefNoFin: fmt.Sprintf("%[1]sArg, _ := WrapString(%[1]s)", arg.Name),
		Finalizer:   fmt.Sprintf("%sFin()", arg.Name),
	}
}

func charPtrPtrW(arg ArgDef) ArgumentWrapperData {
	return ArgumentWrapperData{
		ArgType:     "[]string",
		VarName:     fmt.Sprintf("%sArg", arg.Name),
		ArgDef:      fmt.Sprintf("%[1]sArg, %[1]sFin := WrapStringList(%[1]s)", arg.Name),
		ArgDefNoFin: fmt.Sprintf("%[1]sArg, _ := WrapStringList(%[1]s)", arg.Name),
		Finalizer:   fmt.Sprintf("%sFin()", arg.Name),
	}
}

func uCharPtrW(arg ArgDef) ArgumentWrapperData {
	return ArgumentWrapperData{
		ArgType: "*C.uchar",
		VarName: fmt.Sprintf("&%s", arg.Name),
	}
}

func sizeTPtrW(arg ArgDef) ArgumentWrapperData {
	return ArgumentWrapperData{
		ArgType: "*uint64",
		VarName: fmt.Sprintf("(*C.xulong)(%s)", arg.Name),
	}
}

func floatArrayW(arg ArgDef) ArgumentWrapperData {
	return ArgumentWrapperData{
		ArgType: "[]float32",
		VarName: fmt.Sprintf("(*C.float)(&(%s[0]))", arg.Name),
	}
}

func boolPtrW(arg ArgDef) ArgumentWrapperData {
	return ArgumentWrapperData{
		ArgType:     "*bool",
		ArgDef:      fmt.Sprintf("%[1]sArg, %[1]sFin := WrapBool(%[1]s)", arg.Name),
		ArgDefNoFin: fmt.Sprintf("%[1]sArg, _ := WrapBool(%[1]s)", arg.Name),
		Finalizer:   fmt.Sprintf("%[1]sFin()", arg.Name),
		VarName:     fmt.Sprintf("%sArg", arg.Name),
	}
}

func int64ArrayW(arg ArgDef) ArgumentWrapperData {
	return ArgumentWrapperData{
		ArgType: "[]int64",
		VarName: fmt.Sprintf("(*C.longlong)(&(%s[0]))", arg.Name),
	}
}

func uint64ArrayW(arg ArgDef) ArgumentWrapperData {
	return ArgumentWrapperData{
		ArgType: "[]uint64",
		VarName: fmt.Sprintf("(*C.ulonglong)(&(%s[0]))", arg.Name),
	}
}

func inputeTextCallbackW(arg ArgDef) (argType string, def string, varName string) {
	argType = "ImGuiInputTextCallback"
	// TODO: implement me
	return
}

// generic wrappers:

// C.int -> int32
func simpleW(goType GoIdentifier, cType CIdentifier) argumentWrapper {
	return func(arg ArgDef) ArgumentWrapperData {
		return ArgumentWrapperData{
			ArgType: goType,
			VarName: fmt.Sprintf("%s(%s)", cType, arg.Name),
		}
	}
}

// C.int* -> *int32
//
//	return simplePtrW(arg.Name, "int16", "C.int")
func simplePtrW(goType GoIdentifier, cType CIdentifier) argumentWrapper {
	return func(arg ArgDef) ArgumentWrapperData {
		return ArgumentWrapperData{
			ArgType:     GoIdentifier(fmt.Sprintf("*%s", goType)),
			ArgDef:      fmt.Sprintf("%[1]sArg, %[1]sFin := WrapNumberPtr[%[2]s, %[3]s](%[1]s)", arg.Name, cType, goType),
			ArgDefNoFin: fmt.Sprintf("%[1]sArg, _ := WrapNumberPtr[%[2]s, %[3]s](%[1]s)", arg.Name, cType, goType),
			Finalizer:   fmt.Sprintf("%[1]sFin()", arg.Name, cType, goType),
			VarName:     fmt.Sprintf("%sArg", arg.Name),
		}
	}
}

// C.int*, C.int[] as well as C.int[2] -> [2]*int32
func simplePtrArrayW(size int, cArrayType CIdentifier, goArrayType GoIdentifier) argumentWrapper {
	return func(arg ArgDef) ArgumentWrapperData {
		def := fmt.Sprintf(`
%[1]sArg := make([]%[2]s, len(%[1]s))
for i, %[1]sV := range %[1]s {
  %[1]sArg[i] = %[2]s(%[1]sV)
}`, arg.Name, cArrayType)
		return ArgumentWrapperData{
			ArgType:     GoIdentifier(fmt.Sprintf("*[%d]%s", size, goArrayType)),
			ArgDef:      def,
			ArgDefNoFin: def,
			VarName:     fmt.Sprintf("(*%s)(&%sArg[0])", cArrayType, arg.Name),
			Finalizer: fmt.Sprintf(`
for i, %[1]sV := range %[1]sArg {
	(*%[1]s)[i] = %[3]s(%[1]sV)
}

`, arg.Name, cArrayType, goArrayType),
		}
	}
}

// C.int*, C.int[] -> *[]int32
func simplePtrSliceW(cArrayType, goArrayType string) argumentWrapper {
	return func(arg ArgDef) ArgumentWrapperData {
		def := fmt.Sprintf(`%[1]sArg := make([]%[2]s, len(*%[1]s))
for i, %[1]sV := range *%[1]s {
  %[1]sArg[i] = %[2]s(%[1]sV)
}
`, arg.Name, cArrayType, goArrayType)
		return ArgumentWrapperData{
			ArgType:     GoIdentifier(fmt.Sprintf("*[]%s", goArrayType)),
			ArgDef:      def,
			ArgDefNoFin: def,
			Finalizer: fmt.Sprintf(`
  for i, %[1]sV := range %[1]sArg {
    (*%[1]s)[i] = %[3]s(%[1]sV)
  }
`, arg.Name, cArrayType, goArrayType),
			VarName: fmt.Sprintf("(*%s)(&%sArg[0])", cArrayType, arg.Name),
		}
	}
}

// C.ImVec2 -> ImVec2
func wrappableW(sType GoIdentifier) argumentWrapper {
	return func(arg ArgDef) ArgumentWrapperData {
		return ArgumentWrapperData{
			ArgType: sType,
			VarName: fmt.Sprintf("%s.toC()", arg.Name),
		}
	}
}

// C.ImVec2* -> *ImVec2
func wrappablePtrW(goType GoIdentifier, cType CIdentifier) argumentWrapper {
	return func(arg ArgDef) ArgumentWrapperData {
		return ArgumentWrapperData{
			ArgType:     goType,
			ArgDef:      fmt.Sprintf("%[1]sArg, %[1]sFin := wrap[%[3]s, %[2]s](%[1]s)", arg.Name, goType, cType),
			ArgDefNoFin: fmt.Sprintf("%[1]sArg, _ := wrap[%[3]s, %[2]s](%[1]s)", arg.Name, goType, cType),
			Finalizer:   fmt.Sprintf("%[1]sFin()", arg.Name, goType, cType),
			VarName:     fmt.Sprintf("%sArg", arg.Name),
		}
	}
}

func wrappablePtrArrayW(size int, cArrayType CIdentifier, goArrayType GoIdentifier) argumentWrapper {
	return func(arg ArgDef) ArgumentWrapperData {
		def := fmt.Sprintf(`%[1]sArg := make([]%[2]s, len(%[1]s))
%[1]sFin := make([]func(), len(%[1]s))
for i, %[1]sV := range %[1]s {
	var tmp *%[2]s
  	tmp, %[1]sFin[i] = wrap[%[2]s, *%[3]s](%[1]sV)
  	%[1]sArg[i] = *tmp
}
`, arg.Name, cArrayType, goArrayType)
		return ArgumentWrapperData{
			ArgType:     GoIdentifier(fmt.Sprintf("[%d]*%s", size, goArrayType)),
			ArgDef:      def,
			ArgDefNoFin: def,
			Finalizer: fmt.Sprintf(`
  for _, %[1]sV := range %[1]sFin {
    %[1]sV()
  }
`, arg.Name, cArrayType, goArrayType),
			VarName: fmt.Sprintf("(*%s)(&%sArg[0])", cArrayType, arg.Name),
		}
	}
}
