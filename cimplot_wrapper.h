// Code generated by cmd/codegen from https://github.com/AllenDang/cimgui-go.
// DO NOT EDIT.

#pragma once

#include "cimplot/cimplot.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void wrap_ImPlotAnnotationCollection_Append(ImPlotAnnotationCollection* self,const ImVec2 pos,const ImVec2 off,ImU32 bg,ImU32 fg,bool clamp,const char* fmt);
extern void wrap_ImPlotTagCollection_Append(ImPlotTagCollection* self,ImAxis axis,double value,ImU32 bg,ImU32 fg,const char* fmt);
extern void wrap_ImPlot_AddTextCenteredV(ImDrawList* DrawList,ImVec2 top_center,ImU32 col,const char* text_begin);
extern void wrap_ImPlot_AddTextVerticalV(ImDrawList* DrawList,ImVec2 pos,ImU32 col,const char* text_begin);
extern void wrap_ImPlot_Annotation_Str(double x,double y,const ImVec4 col,const ImVec2 pix_offset,bool clamp,const char* fmt);
extern void wrap_ImPlot_TagX_Str(double x,const ImVec4 col,const char* fmt);
extern void wrap_ImPlot_TagY_Str(double y,const ImVec4 col,const char* fmt);
extern bool wrap_ImPlotAxis_SetMax(ImPlotAxis* self,double _max);
extern bool wrap_ImPlotAxis_SetMin(ImPlotAxis* self,double _min);
extern ImPlotColormap wrap_ImPlot_AddColormap_U32Ptr(const char* name,const ImU32* cols,int size);
extern ImPlotColormap wrap_ImPlot_AddColormap_Vec4Ptr(const char* name,const ImVec4* cols,int size);
extern void wrap_ImPlot_AddTextCentered(ImDrawList* DrawList,ImVec2 top_center,ImU32 col,const char* text_begin);
extern void wrap_ImPlot_AddTextVertical(ImDrawList* DrawList,ImVec2 pos,ImU32 col,const char* text_begin);
extern void wrap_ImPlot_Annotation_Bool(double x,double y,const ImVec4 col,const ImVec2 pix_offset,bool clamp);
extern bool wrap_ImPlot_BeginAlignedPlots(const char* group_id);
extern bool wrap_ImPlot_BeginDragDropSourceAxis(ImAxis axis);
extern bool wrap_ImPlot_BeginDragDropSourceItem(const char* label_id);
extern bool wrap_ImPlot_BeginDragDropSourcePlot();
extern bool wrap_ImPlot_BeginItem(const char* label_id);
extern bool wrap_ImPlot_BeginLegendPopup(const char* label_id);
extern bool wrap_ImPlot_BeginPlot(const char* title_id);
extern bool wrap_ImPlot_BeginSubplots(const char* title_id,int rows,int cols,const ImVec2 size);
extern void wrap_ImPlot_BustColorCache();
extern bool wrap_ImPlot_ColormapButton(const char* label);
extern void wrap_ImPlot_ColormapScale(const char* label,double scale_min,double scale_max);
extern bool wrap_ImPlot_ColormapSlider(const char* label,float* t);
extern void wrap_ImPlot_DestroyContext();
extern bool wrap_ImPlot_DragLineX(int id,double* x,const ImVec4 col);
extern bool wrap_ImPlot_DragLineY(int id,double* y,const ImVec4 col);
extern bool wrap_ImPlot_DragPoint(int id,double* x,double* y,const ImVec4 col);
extern bool wrap_ImPlot_DragRect(int id,double* x1,double* y1,double* x2,double* y2,const ImVec4 col);
extern void wrap_ImPlot_GetColormapColor(ImVec4* pOut,int idx);
extern int wrap_ImPlot_GetColormapSize();
extern void wrap_ImPlot_GetLocationPos(ImVec2* pOut,const ImRect outer_rect,const ImVec2 inner_size,ImPlotLocation location);
extern ImPlotRect wrap_ImPlot_GetPlotLimits();
extern void wrap_ImPlot_GetPlotMousePos(ImPlotPoint* pOut);
extern ImPlotRect wrap_ImPlot_GetPlotSelection();
extern void wrap_ImPlot_HideNextItem();
extern bool wrap_ImPlot_ImAlmostEqual(double v1,double v2);
extern void wrap_ImPlot_LabelAxisValue(const ImPlotAxis axis,double value,char* buff,int size);
extern void wrap_ImPlot_MapInputDefault();
extern void wrap_ImPlot_MapInputReverse();
extern void wrap_ImPlot_PixelsToPlot_Float(ImPlotPoint* pOut,float x,float y);
extern void wrap_ImPlot_PixelsToPlot_Vec2(ImPlotPoint* pOut,const ImVec2 pix);
extern void wrap_ImPlot_PlotBarGroups_FloatPtr(const char* const label_ids[],const float* values,int item_count,int group_count);
extern void wrap_ImPlot_PlotBarGroups_S16Ptr(const char* const label_ids[],const ImS16* values,int item_count,int group_count);
extern void wrap_ImPlot_PlotBarGroups_S32Ptr(const char* const label_ids[],const ImS32* values,int item_count,int group_count);
extern void wrap_ImPlot_PlotBarGroups_S64Ptr(const char* const label_ids[],const ImS64* values,int item_count,int group_count);
extern void wrap_ImPlot_PlotBarGroups_S8Ptr(const char* const label_ids[],const ImS8* values,int item_count,int group_count);
extern void wrap_ImPlot_PlotBarGroups_U16Ptr(const char* const label_ids[],const ImU16* values,int item_count,int group_count);
extern void wrap_ImPlot_PlotBarGroups_U32Ptr(const char* const label_ids[],const ImU32* values,int item_count,int group_count);
extern void wrap_ImPlot_PlotBarGroups_U64Ptr(const char* const label_ids[],const ImU64* values,int item_count,int group_count);
extern void wrap_ImPlot_PlotBarGroups_U8Ptr(const char* const label_ids[],const ImU8* values,int item_count,int group_count);
extern void wrap_ImPlot_PlotBarGroups_doublePtr(const char* const label_ids[],const double* values,int item_count,int group_count);
extern void wrap_ImPlot_PlotBarsG(const char* label_id,ImPlotPoint_getter getter,void* data,int count,double bar_size);
extern void wrap_ImPlot_PlotBars_FloatPtrFloatPtr(const char* label_id,const float* xs,const float* ys,int count,double bar_size);
extern void wrap_ImPlot_PlotBars_FloatPtrInt(const char* label_id,const float* values,int count);
extern void wrap_ImPlot_PlotBars_S16PtrInt(const char* label_id,const ImS16* values,int count);
extern void wrap_ImPlot_PlotBars_S16PtrS16Ptr(const char* label_id,const ImS16* xs,const ImS16* ys,int count,double bar_size);
extern void wrap_ImPlot_PlotBars_S32PtrInt(const char* label_id,const ImS32* values,int count);
extern void wrap_ImPlot_PlotBars_S32PtrS32Ptr(const char* label_id,const ImS32* xs,const ImS32* ys,int count,double bar_size);
extern void wrap_ImPlot_PlotBars_S64PtrInt(const char* label_id,const ImS64* values,int count);
extern void wrap_ImPlot_PlotBars_S64PtrS64Ptr(const char* label_id,const ImS64* xs,const ImS64* ys,int count,double bar_size);
extern void wrap_ImPlot_PlotBars_S8PtrInt(const char* label_id,const ImS8* values,int count);
extern void wrap_ImPlot_PlotBars_S8PtrS8Ptr(const char* label_id,const ImS8* xs,const ImS8* ys,int count,double bar_size);
extern void wrap_ImPlot_PlotBars_U16PtrInt(const char* label_id,const ImU16* values,int count);
extern void wrap_ImPlot_PlotBars_U16PtrU16Ptr(const char* label_id,const ImU16* xs,const ImU16* ys,int count,double bar_size);
extern void wrap_ImPlot_PlotBars_U32PtrInt(const char* label_id,const ImU32* values,int count);
extern void wrap_ImPlot_PlotBars_U32PtrU32Ptr(const char* label_id,const ImU32* xs,const ImU32* ys,int count,double bar_size);
extern void wrap_ImPlot_PlotBars_U64PtrInt(const char* label_id,const ImU64* values,int count);
extern void wrap_ImPlot_PlotBars_U64PtrU64Ptr(const char* label_id,const ImU64* xs,const ImU64* ys,int count,double bar_size);
extern void wrap_ImPlot_PlotBars_U8PtrInt(const char* label_id,const ImU8* values,int count);
extern void wrap_ImPlot_PlotBars_U8PtrU8Ptr(const char* label_id,const ImU8* xs,const ImU8* ys,int count,double bar_size);
extern void wrap_ImPlot_PlotBars_doublePtrInt(const char* label_id,const double* values,int count);
extern void wrap_ImPlot_PlotBars_doublePtrdoublePtr(const char* label_id,const double* xs,const double* ys,int count,double bar_size);
extern void wrap_ImPlot_PlotDigitalG(const char* label_id,ImPlotPoint_getter getter,void* data,int count);
extern void wrap_ImPlot_PlotDigital_FloatPtr(const char* label_id,const float* xs,const float* ys,int count);
extern void wrap_ImPlot_PlotDigital_S16Ptr(const char* label_id,const ImS16* xs,const ImS16* ys,int count);
extern void wrap_ImPlot_PlotDigital_S32Ptr(const char* label_id,const ImS32* xs,const ImS32* ys,int count);
extern void wrap_ImPlot_PlotDigital_S64Ptr(const char* label_id,const ImS64* xs,const ImS64* ys,int count);
extern void wrap_ImPlot_PlotDigital_S8Ptr(const char* label_id,const ImS8* xs,const ImS8* ys,int count);
extern void wrap_ImPlot_PlotDigital_U16Ptr(const char* label_id,const ImU16* xs,const ImU16* ys,int count);
extern void wrap_ImPlot_PlotDigital_U32Ptr(const char* label_id,const ImU32* xs,const ImU32* ys,int count);
extern void wrap_ImPlot_PlotDigital_U64Ptr(const char* label_id,const ImU64* xs,const ImU64* ys,int count);
extern void wrap_ImPlot_PlotDigital_U8Ptr(const char* label_id,const ImU8* xs,const ImU8* ys,int count);
extern void wrap_ImPlot_PlotDigital_doublePtr(const char* label_id,const double* xs,const double* ys,int count);
extern void wrap_ImPlot_PlotDummy(const char* label_id);
extern void wrap_ImPlot_PlotErrorBars_FloatPtrFloatPtrFloatPtrFloatPtr(const char* label_id,const float* xs,const float* ys,const float* neg,const float* pos,int count);
extern void wrap_ImPlot_PlotErrorBars_FloatPtrFloatPtrFloatPtrInt(const char* label_id,const float* xs,const float* ys,const float* err,int count);
extern void wrap_ImPlot_PlotErrorBars_S16PtrS16PtrS16PtrInt(const char* label_id,const ImS16* xs,const ImS16* ys,const ImS16* err,int count);
extern void wrap_ImPlot_PlotErrorBars_S16PtrS16PtrS16PtrS16Ptr(const char* label_id,const ImS16* xs,const ImS16* ys,const ImS16* neg,const ImS16* pos,int count);
extern void wrap_ImPlot_PlotErrorBars_S32PtrS32PtrS32PtrInt(const char* label_id,const ImS32* xs,const ImS32* ys,const ImS32* err,int count);
extern void wrap_ImPlot_PlotErrorBars_S32PtrS32PtrS32PtrS32Ptr(const char* label_id,const ImS32* xs,const ImS32* ys,const ImS32* neg,const ImS32* pos,int count);
extern void wrap_ImPlot_PlotErrorBars_S64PtrS64PtrS64PtrInt(const char* label_id,const ImS64* xs,const ImS64* ys,const ImS64* err,int count);
extern void wrap_ImPlot_PlotErrorBars_S64PtrS64PtrS64PtrS64Ptr(const char* label_id,const ImS64* xs,const ImS64* ys,const ImS64* neg,const ImS64* pos,int count);
extern void wrap_ImPlot_PlotErrorBars_S8PtrS8PtrS8PtrInt(const char* label_id,const ImS8* xs,const ImS8* ys,const ImS8* err,int count);
extern void wrap_ImPlot_PlotErrorBars_S8PtrS8PtrS8PtrS8Ptr(const char* label_id,const ImS8* xs,const ImS8* ys,const ImS8* neg,const ImS8* pos,int count);
extern void wrap_ImPlot_PlotErrorBars_U16PtrU16PtrU16PtrInt(const char* label_id,const ImU16* xs,const ImU16* ys,const ImU16* err,int count);
extern void wrap_ImPlot_PlotErrorBars_U16PtrU16PtrU16PtrU16Ptr(const char* label_id,const ImU16* xs,const ImU16* ys,const ImU16* neg,const ImU16* pos,int count);
extern void wrap_ImPlot_PlotErrorBars_U32PtrU32PtrU32PtrInt(const char* label_id,const ImU32* xs,const ImU32* ys,const ImU32* err,int count);
extern void wrap_ImPlot_PlotErrorBars_U32PtrU32PtrU32PtrU32Ptr(const char* label_id,const ImU32* xs,const ImU32* ys,const ImU32* neg,const ImU32* pos,int count);
extern void wrap_ImPlot_PlotErrorBars_U64PtrU64PtrU64PtrInt(const char* label_id,const ImU64* xs,const ImU64* ys,const ImU64* err,int count);
extern void wrap_ImPlot_PlotErrorBars_U64PtrU64PtrU64PtrU64Ptr(const char* label_id,const ImU64* xs,const ImU64* ys,const ImU64* neg,const ImU64* pos,int count);
extern void wrap_ImPlot_PlotErrorBars_U8PtrU8PtrU8PtrInt(const char* label_id,const ImU8* xs,const ImU8* ys,const ImU8* err,int count);
extern void wrap_ImPlot_PlotErrorBars_U8PtrU8PtrU8PtrU8Ptr(const char* label_id,const ImU8* xs,const ImU8* ys,const ImU8* neg,const ImU8* pos,int count);
extern void wrap_ImPlot_PlotErrorBars_doublePtrdoublePtrdoublePtrInt(const char* label_id,const double* xs,const double* ys,const double* err,int count);
extern void wrap_ImPlot_PlotErrorBars_doublePtrdoublePtrdoublePtrdoublePtr(const char* label_id,const double* xs,const double* ys,const double* neg,const double* pos,int count);
extern void wrap_ImPlot_PlotHeatmap_FloatPtr(const char* label_id,const float* values,int rows,int cols);
extern void wrap_ImPlot_PlotHeatmap_S16Ptr(const char* label_id,const ImS16* values,int rows,int cols);
extern void wrap_ImPlot_PlotHeatmap_S32Ptr(const char* label_id,const ImS32* values,int rows,int cols);
extern void wrap_ImPlot_PlotHeatmap_S64Ptr(const char* label_id,const ImS64* values,int rows,int cols);
extern void wrap_ImPlot_PlotHeatmap_S8Ptr(const char* label_id,const ImS8* values,int rows,int cols);
extern void wrap_ImPlot_PlotHeatmap_U16Ptr(const char* label_id,const ImU16* values,int rows,int cols);
extern void wrap_ImPlot_PlotHeatmap_U32Ptr(const char* label_id,const ImU32* values,int rows,int cols);
extern void wrap_ImPlot_PlotHeatmap_U64Ptr(const char* label_id,const ImU64* values,int rows,int cols);
extern void wrap_ImPlot_PlotHeatmap_U8Ptr(const char* label_id,const ImU8* values,int rows,int cols);
extern void wrap_ImPlot_PlotHeatmap_doublePtr(const char* label_id,const double* values,int rows,int cols);
extern double wrap_ImPlot_PlotHistogram2D_FloatPtr(const char* label_id,const float* xs,const float* ys,int count);
extern double wrap_ImPlot_PlotHistogram2D_S16Ptr(const char* label_id,const ImS16* xs,const ImS16* ys,int count);
extern double wrap_ImPlot_PlotHistogram2D_S32Ptr(const char* label_id,const ImS32* xs,const ImS32* ys,int count);
extern double wrap_ImPlot_PlotHistogram2D_S64Ptr(const char* label_id,const ImS64* xs,const ImS64* ys,int count);
extern double wrap_ImPlot_PlotHistogram2D_S8Ptr(const char* label_id,const ImS8* xs,const ImS8* ys,int count);
extern double wrap_ImPlot_PlotHistogram2D_U16Ptr(const char* label_id,const ImU16* xs,const ImU16* ys,int count);
extern double wrap_ImPlot_PlotHistogram2D_U32Ptr(const char* label_id,const ImU32* xs,const ImU32* ys,int count);
extern double wrap_ImPlot_PlotHistogram2D_U64Ptr(const char* label_id,const ImU64* xs,const ImU64* ys,int count);
extern double wrap_ImPlot_PlotHistogram2D_U8Ptr(const char* label_id,const ImU8* xs,const ImU8* ys,int count);
extern double wrap_ImPlot_PlotHistogram2D_doublePtr(const char* label_id,const double* xs,const double* ys,int count);
extern double wrap_ImPlot_PlotHistogram_FloatPtr(const char* label_id,const float* values,int count);
extern double wrap_ImPlot_PlotHistogram_S16Ptr(const char* label_id,const ImS16* values,int count);
extern double wrap_ImPlot_PlotHistogram_S32Ptr(const char* label_id,const ImS32* values,int count);
extern double wrap_ImPlot_PlotHistogram_S64Ptr(const char* label_id,const ImS64* values,int count);
extern double wrap_ImPlot_PlotHistogram_S8Ptr(const char* label_id,const ImS8* values,int count);
extern double wrap_ImPlot_PlotHistogram_U16Ptr(const char* label_id,const ImU16* values,int count);
extern double wrap_ImPlot_PlotHistogram_U32Ptr(const char* label_id,const ImU32* values,int count);
extern double wrap_ImPlot_PlotHistogram_U64Ptr(const char* label_id,const ImU64* values,int count);
extern double wrap_ImPlot_PlotHistogram_U8Ptr(const char* label_id,const ImU8* values,int count);
extern double wrap_ImPlot_PlotHistogram_doublePtr(const char* label_id,const double* values,int count);
extern void wrap_ImPlot_PlotImage(const char* label_id,ImTextureID user_texture_id,const ImPlotPoint bounds_min,const ImPlotPoint bounds_max);
extern void wrap_ImPlot_PlotInfLines_FloatPtr(const char* label_id,const float* values,int count);
extern void wrap_ImPlot_PlotInfLines_S16Ptr(const char* label_id,const ImS16* values,int count);
extern void wrap_ImPlot_PlotInfLines_S32Ptr(const char* label_id,const ImS32* values,int count);
extern void wrap_ImPlot_PlotInfLines_S64Ptr(const char* label_id,const ImS64* values,int count);
extern void wrap_ImPlot_PlotInfLines_S8Ptr(const char* label_id,const ImS8* values,int count);
extern void wrap_ImPlot_PlotInfLines_U16Ptr(const char* label_id,const ImU16* values,int count);
extern void wrap_ImPlot_PlotInfLines_U32Ptr(const char* label_id,const ImU32* values,int count);
extern void wrap_ImPlot_PlotInfLines_U64Ptr(const char* label_id,const ImU64* values,int count);
extern void wrap_ImPlot_PlotInfLines_U8Ptr(const char* label_id,const ImU8* values,int count);
extern void wrap_ImPlot_PlotInfLines_doublePtr(const char* label_id,const double* values,int count);
extern void wrap_ImPlot_PlotLineG(const char* label_id,ImPlotPoint_getter getter,void* data,int count);
extern void wrap_ImPlot_PlotLine_FloatPtrFloatPtr(const char* label_id,const float* xs,const float* ys,int count);
extern void wrap_ImPlot_PlotLine_FloatPtrInt(const char* label_id,const float* values,int count);
extern void wrap_ImPlot_PlotLine_S16PtrInt(const char* label_id,const ImS16* values,int count);
extern void wrap_ImPlot_PlotLine_S16PtrS16Ptr(const char* label_id,const ImS16* xs,const ImS16* ys,int count);
extern void wrap_ImPlot_PlotLine_S32PtrInt(const char* label_id,const ImS32* values,int count);
extern void wrap_ImPlot_PlotLine_S32PtrS32Ptr(const char* label_id,const ImS32* xs,const ImS32* ys,int count);
extern void wrap_ImPlot_PlotLine_S64PtrInt(const char* label_id,const ImS64* values,int count);
extern void wrap_ImPlot_PlotLine_S64PtrS64Ptr(const char* label_id,const ImS64* xs,const ImS64* ys,int count);
extern void wrap_ImPlot_PlotLine_S8PtrInt(const char* label_id,const ImS8* values,int count);
extern void wrap_ImPlot_PlotLine_S8PtrS8Ptr(const char* label_id,const ImS8* xs,const ImS8* ys,int count);
extern void wrap_ImPlot_PlotLine_U16PtrInt(const char* label_id,const ImU16* values,int count);
extern void wrap_ImPlot_PlotLine_U16PtrU16Ptr(const char* label_id,const ImU16* xs,const ImU16* ys,int count);
extern void wrap_ImPlot_PlotLine_U32PtrInt(const char* label_id,const ImU32* values,int count);
extern void wrap_ImPlot_PlotLine_U32PtrU32Ptr(const char* label_id,const ImU32* xs,const ImU32* ys,int count);
extern void wrap_ImPlot_PlotLine_U64PtrInt(const char* label_id,const ImU64* values,int count);
extern void wrap_ImPlot_PlotLine_U64PtrU64Ptr(const char* label_id,const ImU64* xs,const ImU64* ys,int count);
extern void wrap_ImPlot_PlotLine_U8PtrInt(const char* label_id,const ImU8* values,int count);
extern void wrap_ImPlot_PlotLine_U8PtrU8Ptr(const char* label_id,const ImU8* xs,const ImU8* ys,int count);
extern void wrap_ImPlot_PlotLine_doublePtrInt(const char* label_id,const double* values,int count);
extern void wrap_ImPlot_PlotLine_doublePtrdoublePtr(const char* label_id,const double* xs,const double* ys,int count);
extern void wrap_ImPlot_PlotPieChart_FloatPtr(const char* const label_ids[],const float* values,int count,double x,double y,double radius);
extern void wrap_ImPlot_PlotPieChart_S16Ptr(const char* const label_ids[],const ImS16* values,int count,double x,double y,double radius);
extern void wrap_ImPlot_PlotPieChart_S32Ptr(const char* const label_ids[],const ImS32* values,int count,double x,double y,double radius);
extern void wrap_ImPlot_PlotPieChart_S64Ptr(const char* const label_ids[],const ImS64* values,int count,double x,double y,double radius);
extern void wrap_ImPlot_PlotPieChart_S8Ptr(const char* const label_ids[],const ImS8* values,int count,double x,double y,double radius);
extern void wrap_ImPlot_PlotPieChart_U16Ptr(const char* const label_ids[],const ImU16* values,int count,double x,double y,double radius);
extern void wrap_ImPlot_PlotPieChart_U32Ptr(const char* const label_ids[],const ImU32* values,int count,double x,double y,double radius);
extern void wrap_ImPlot_PlotPieChart_U64Ptr(const char* const label_ids[],const ImU64* values,int count,double x,double y,double radius);
extern void wrap_ImPlot_PlotPieChart_U8Ptr(const char* const label_ids[],const ImU8* values,int count,double x,double y,double radius);
extern void wrap_ImPlot_PlotPieChart_doublePtr(const char* const label_ids[],const double* values,int count,double x,double y,double radius);
extern void wrap_ImPlot_PlotScatterG(const char* label_id,ImPlotPoint_getter getter,void* data,int count);
extern void wrap_ImPlot_PlotScatter_FloatPtrFloatPtr(const char* label_id,const float* xs,const float* ys,int count);
extern void wrap_ImPlot_PlotScatter_FloatPtrInt(const char* label_id,const float* values,int count);
extern void wrap_ImPlot_PlotScatter_S16PtrInt(const char* label_id,const ImS16* values,int count);
extern void wrap_ImPlot_PlotScatter_S16PtrS16Ptr(const char* label_id,const ImS16* xs,const ImS16* ys,int count);
extern void wrap_ImPlot_PlotScatter_S32PtrInt(const char* label_id,const ImS32* values,int count);
extern void wrap_ImPlot_PlotScatter_S32PtrS32Ptr(const char* label_id,const ImS32* xs,const ImS32* ys,int count);
extern void wrap_ImPlot_PlotScatter_S64PtrInt(const char* label_id,const ImS64* values,int count);
extern void wrap_ImPlot_PlotScatter_S64PtrS64Ptr(const char* label_id,const ImS64* xs,const ImS64* ys,int count);
extern void wrap_ImPlot_PlotScatter_S8PtrInt(const char* label_id,const ImS8* values,int count);
extern void wrap_ImPlot_PlotScatter_S8PtrS8Ptr(const char* label_id,const ImS8* xs,const ImS8* ys,int count);
extern void wrap_ImPlot_PlotScatter_U16PtrInt(const char* label_id,const ImU16* values,int count);
extern void wrap_ImPlot_PlotScatter_U16PtrU16Ptr(const char* label_id,const ImU16* xs,const ImU16* ys,int count);
extern void wrap_ImPlot_PlotScatter_U32PtrInt(const char* label_id,const ImU32* values,int count);
extern void wrap_ImPlot_PlotScatter_U32PtrU32Ptr(const char* label_id,const ImU32* xs,const ImU32* ys,int count);
extern void wrap_ImPlot_PlotScatter_U64PtrInt(const char* label_id,const ImU64* values,int count);
extern void wrap_ImPlot_PlotScatter_U64PtrU64Ptr(const char* label_id,const ImU64* xs,const ImU64* ys,int count);
extern void wrap_ImPlot_PlotScatter_U8PtrInt(const char* label_id,const ImU8* values,int count);
extern void wrap_ImPlot_PlotScatter_U8PtrU8Ptr(const char* label_id,const ImU8* xs,const ImU8* ys,int count);
extern void wrap_ImPlot_PlotScatter_doublePtrInt(const char* label_id,const double* values,int count);
extern void wrap_ImPlot_PlotScatter_doublePtrdoublePtr(const char* label_id,const double* xs,const double* ys,int count);
extern void wrap_ImPlot_PlotShadedG(const char* label_id,ImPlotPoint_getter getter1,void* data1,ImPlotPoint_getter getter2,void* data2,int count);
extern void wrap_ImPlot_PlotShaded_FloatPtrFloatPtrFloatPtr(const char* label_id,const float* xs,const float* ys1,const float* ys2,int count);
extern void wrap_ImPlot_PlotShaded_FloatPtrFloatPtrInt(const char* label_id,const float* xs,const float* ys,int count);
extern void wrap_ImPlot_PlotShaded_FloatPtrInt(const char* label_id,const float* values,int count);
extern void wrap_ImPlot_PlotShaded_S16PtrInt(const char* label_id,const ImS16* values,int count);
extern void wrap_ImPlot_PlotShaded_S16PtrS16PtrInt(const char* label_id,const ImS16* xs,const ImS16* ys,int count);
extern void wrap_ImPlot_PlotShaded_S16PtrS16PtrS16Ptr(const char* label_id,const ImS16* xs,const ImS16* ys1,const ImS16* ys2,int count);
extern void wrap_ImPlot_PlotShaded_S32PtrInt(const char* label_id,const ImS32* values,int count);
extern void wrap_ImPlot_PlotShaded_S32PtrS32PtrInt(const char* label_id,const ImS32* xs,const ImS32* ys,int count);
extern void wrap_ImPlot_PlotShaded_S32PtrS32PtrS32Ptr(const char* label_id,const ImS32* xs,const ImS32* ys1,const ImS32* ys2,int count);
extern void wrap_ImPlot_PlotShaded_S64PtrInt(const char* label_id,const ImS64* values,int count);
extern void wrap_ImPlot_PlotShaded_S64PtrS64PtrInt(const char* label_id,const ImS64* xs,const ImS64* ys,int count);
extern void wrap_ImPlot_PlotShaded_S64PtrS64PtrS64Ptr(const char* label_id,const ImS64* xs,const ImS64* ys1,const ImS64* ys2,int count);
extern void wrap_ImPlot_PlotShaded_S8PtrInt(const char* label_id,const ImS8* values,int count);
extern void wrap_ImPlot_PlotShaded_S8PtrS8PtrInt(const char* label_id,const ImS8* xs,const ImS8* ys,int count);
extern void wrap_ImPlot_PlotShaded_S8PtrS8PtrS8Ptr(const char* label_id,const ImS8* xs,const ImS8* ys1,const ImS8* ys2,int count);
extern void wrap_ImPlot_PlotShaded_U16PtrInt(const char* label_id,const ImU16* values,int count);
extern void wrap_ImPlot_PlotShaded_U16PtrU16PtrInt(const char* label_id,const ImU16* xs,const ImU16* ys,int count);
extern void wrap_ImPlot_PlotShaded_U16PtrU16PtrU16Ptr(const char* label_id,const ImU16* xs,const ImU16* ys1,const ImU16* ys2,int count);
extern void wrap_ImPlot_PlotShaded_U32PtrInt(const char* label_id,const ImU32* values,int count);
extern void wrap_ImPlot_PlotShaded_U32PtrU32PtrInt(const char* label_id,const ImU32* xs,const ImU32* ys,int count);
extern void wrap_ImPlot_PlotShaded_U32PtrU32PtrU32Ptr(const char* label_id,const ImU32* xs,const ImU32* ys1,const ImU32* ys2,int count);
extern void wrap_ImPlot_PlotShaded_U64PtrInt(const char* label_id,const ImU64* values,int count);
extern void wrap_ImPlot_PlotShaded_U64PtrU64PtrInt(const char* label_id,const ImU64* xs,const ImU64* ys,int count);
extern void wrap_ImPlot_PlotShaded_U64PtrU64PtrU64Ptr(const char* label_id,const ImU64* xs,const ImU64* ys1,const ImU64* ys2,int count);
extern void wrap_ImPlot_PlotShaded_U8PtrInt(const char* label_id,const ImU8* values,int count);
extern void wrap_ImPlot_PlotShaded_U8PtrU8PtrInt(const char* label_id,const ImU8* xs,const ImU8* ys,int count);
extern void wrap_ImPlot_PlotShaded_U8PtrU8PtrU8Ptr(const char* label_id,const ImU8* xs,const ImU8* ys1,const ImU8* ys2,int count);
extern void wrap_ImPlot_PlotShaded_doublePtrInt(const char* label_id,const double* values,int count);
extern void wrap_ImPlot_PlotShaded_doublePtrdoublePtrInt(const char* label_id,const double* xs,const double* ys,int count);
extern void wrap_ImPlot_PlotShaded_doublePtrdoublePtrdoublePtr(const char* label_id,const double* xs,const double* ys1,const double* ys2,int count);
extern void wrap_ImPlot_PlotStairsG(const char* label_id,ImPlotPoint_getter getter,void* data,int count);
extern void wrap_ImPlot_PlotStairs_FloatPtrFloatPtr(const char* label_id,const float* xs,const float* ys,int count);
extern void wrap_ImPlot_PlotStairs_FloatPtrInt(const char* label_id,const float* values,int count);
extern void wrap_ImPlot_PlotStairs_S16PtrInt(const char* label_id,const ImS16* values,int count);
extern void wrap_ImPlot_PlotStairs_S16PtrS16Ptr(const char* label_id,const ImS16* xs,const ImS16* ys,int count);
extern void wrap_ImPlot_PlotStairs_S32PtrInt(const char* label_id,const ImS32* values,int count);
extern void wrap_ImPlot_PlotStairs_S32PtrS32Ptr(const char* label_id,const ImS32* xs,const ImS32* ys,int count);
extern void wrap_ImPlot_PlotStairs_S64PtrInt(const char* label_id,const ImS64* values,int count);
extern void wrap_ImPlot_PlotStairs_S64PtrS64Ptr(const char* label_id,const ImS64* xs,const ImS64* ys,int count);
extern void wrap_ImPlot_PlotStairs_S8PtrInt(const char* label_id,const ImS8* values,int count);
extern void wrap_ImPlot_PlotStairs_S8PtrS8Ptr(const char* label_id,const ImS8* xs,const ImS8* ys,int count);
extern void wrap_ImPlot_PlotStairs_U16PtrInt(const char* label_id,const ImU16* values,int count);
extern void wrap_ImPlot_PlotStairs_U16PtrU16Ptr(const char* label_id,const ImU16* xs,const ImU16* ys,int count);
extern void wrap_ImPlot_PlotStairs_U32PtrInt(const char* label_id,const ImU32* values,int count);
extern void wrap_ImPlot_PlotStairs_U32PtrU32Ptr(const char* label_id,const ImU32* xs,const ImU32* ys,int count);
extern void wrap_ImPlot_PlotStairs_U64PtrInt(const char* label_id,const ImU64* values,int count);
extern void wrap_ImPlot_PlotStairs_U64PtrU64Ptr(const char* label_id,const ImU64* xs,const ImU64* ys,int count);
extern void wrap_ImPlot_PlotStairs_U8PtrInt(const char* label_id,const ImU8* values,int count);
extern void wrap_ImPlot_PlotStairs_U8PtrU8Ptr(const char* label_id,const ImU8* xs,const ImU8* ys,int count);
extern void wrap_ImPlot_PlotStairs_doublePtrInt(const char* label_id,const double* values,int count);
extern void wrap_ImPlot_PlotStairs_doublePtrdoublePtr(const char* label_id,const double* xs,const double* ys,int count);
extern void wrap_ImPlot_PlotStems_FloatPtrFloatPtr(const char* label_id,const float* xs,const float* ys,int count);
extern void wrap_ImPlot_PlotStems_FloatPtrInt(const char* label_id,const float* values,int count);
extern void wrap_ImPlot_PlotStems_S16PtrInt(const char* label_id,const ImS16* values,int count);
extern void wrap_ImPlot_PlotStems_S16PtrS16Ptr(const char* label_id,const ImS16* xs,const ImS16* ys,int count);
extern void wrap_ImPlot_PlotStems_S32PtrInt(const char* label_id,const ImS32* values,int count);
extern void wrap_ImPlot_PlotStems_S32PtrS32Ptr(const char* label_id,const ImS32* xs,const ImS32* ys,int count);
extern void wrap_ImPlot_PlotStems_S64PtrInt(const char* label_id,const ImS64* values,int count);
extern void wrap_ImPlot_PlotStems_S64PtrS64Ptr(const char* label_id,const ImS64* xs,const ImS64* ys,int count);
extern void wrap_ImPlot_PlotStems_S8PtrInt(const char* label_id,const ImS8* values,int count);
extern void wrap_ImPlot_PlotStems_S8PtrS8Ptr(const char* label_id,const ImS8* xs,const ImS8* ys,int count);
extern void wrap_ImPlot_PlotStems_U16PtrInt(const char* label_id,const ImU16* values,int count);
extern void wrap_ImPlot_PlotStems_U16PtrU16Ptr(const char* label_id,const ImU16* xs,const ImU16* ys,int count);
extern void wrap_ImPlot_PlotStems_U32PtrInt(const char* label_id,const ImU32* values,int count);
extern void wrap_ImPlot_PlotStems_U32PtrU32Ptr(const char* label_id,const ImU32* xs,const ImU32* ys,int count);
extern void wrap_ImPlot_PlotStems_U64PtrInt(const char* label_id,const ImU64* values,int count);
extern void wrap_ImPlot_PlotStems_U64PtrU64Ptr(const char* label_id,const ImU64* xs,const ImU64* ys,int count);
extern void wrap_ImPlot_PlotStems_U8PtrInt(const char* label_id,const ImU8* values,int count);
extern void wrap_ImPlot_PlotStems_U8PtrU8Ptr(const char* label_id,const ImU8* xs,const ImU8* ys,int count);
extern void wrap_ImPlot_PlotStems_doublePtrInt(const char* label_id,const double* values,int count);
extern void wrap_ImPlot_PlotStems_doublePtrdoublePtr(const char* label_id,const double* xs,const double* ys,int count);
extern void wrap_ImPlot_PlotText(const char* text,double x,double y);
extern void wrap_ImPlot_PlotToPixels_PlotPoInt(ImVec2* pOut,const ImPlotPoint plt);
extern void wrap_ImPlot_PlotToPixels_double(ImVec2* pOut,double x,double y);
extern void wrap_ImPlot_PopColormap();
extern void wrap_ImPlot_PopStyleColor();
extern void wrap_ImPlot_PopStyleVar();
extern void wrap_ImPlot_PushPlotClipRect();
extern ImPlotItem* wrap_ImPlot_RegisterOrGetItem(const char* label_id,ImPlotItemFlags flags);
extern void wrap_ImPlot_SampleColormap(ImVec4* pOut,float t);
extern void wrap_ImPlot_SetNextAxesLimits(double x_min,double x_max,double y_min,double y_max);
extern void wrap_ImPlot_SetNextAxisLimits(ImAxis axis,double v_min,double v_max);
extern void wrap_ImPlot_SetNextErrorBarStyle();
extern void wrap_ImPlot_SetNextFillStyle();
extern void wrap_ImPlot_SetNextLineStyle();
extern void wrap_ImPlot_SetNextMarkerStyle();
extern void wrap_ImPlot_SetupAxes(const char* x_label,const char* y_label);
extern void wrap_ImPlot_SetupAxesLimits(double x_min,double x_max,double y_min,double y_max);
extern void wrap_ImPlot_SetupAxis(ImAxis axis);
extern void wrap_ImPlot_SetupAxisFormat_PlotFormatter(ImAxis axis,ImPlotFormatter formatter);
extern void wrap_ImPlot_SetupAxisLimits(ImAxis axis,double v_min,double v_max);
extern void wrap_ImPlot_SetupAxisScale_PlotTransform(ImAxis axis,ImPlotTransform forward,ImPlotTransform inverse);
extern void wrap_ImPlot_SetupAxisTicks_double(ImAxis axis,double v_min,double v_max,int n_ticks);
extern void wrap_ImPlot_SetupAxisTicks_doublePtr(ImAxis axis,const double* values,int n_ticks);
extern void wrap_ImPlot_SetupLegend(ImPlotLocation location);
extern void wrap_ImPlot_SetupMouseText(ImPlotLocation location);
extern void wrap_ImPlot_ShowAltLegend(const char* title_id);
extern void wrap_ImPlot_ShowAxisContextMenu(ImPlotAxis* axis,ImPlotAxis* equal_axis);
extern bool wrap_ImPlot_ShowDatePicker(const char* id,int* level,ImPlotTime* t);
extern void wrap_ImPlot_ShowDemoWindow();
extern void wrap_ImPlot_ShowMetricsWindow();
extern void wrap_ImPlot_ShowStyleEditor();
extern void wrap_ImPlot_StyleColorsAuto();
extern void wrap_ImPlot_StyleColorsClassic();
extern void wrap_ImPlot_StyleColorsDark();
extern void wrap_ImPlot_StyleColorsLight();
extern void wrap_ImPlot_TagX_Bool(double x,const ImVec4 col);
extern void wrap_ImPlot_TagY_Bool(double y,const ImVec4 col);

#ifdef __cplusplus
}
#endif
