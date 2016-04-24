/*
 * This file is AUTO GENERATED - DO NOT MODIFY this file. 
 * This file contains the function prototypes of ODK 1500S.
 *
 * File created by ODK_CodeGenerator version 200.0.2304.1
 * at Sun April 17 19:42:31 2016 
*/

#if !defined    ODK_Functions_H
#define ODK_Functions_H

#include "ODK_Types.h"

#ifdef DLL_EXPORT
  #define EXPORT_API extern "C" __declspec(dllexport)
#else
  #define EXPORT_API extern "C"
#endif

// SobelOperation on a 150x150 greyscale image 
ODK_RESULT SobelFiltImage (
  /*IN*/const ODK_UINT8 image[22500], // input image
  /*OUT*/ODK_UINT8 image_filt[22500]); // filtered output
#define _ODK_FUNCTION_SOBELFILTIMAGE  ODK_RESULT SobelFiltImage (/*IN*/const ODK_UINT8 image[22500], /*OUT*/ODK_UINT8 image_filt[22500])

ODK_RESULT GetTrace (
  /*IN*/const ODK_INT16& TraceCount,
  /*OUT*/ODK_S7STRING TraceBuffer[256][127]);
#define _ODK_FUNCTION_GETTRACE  ODK_RESULT GetTrace (/*IN*/const ODK_INT16& TraceCount, /*OUT*/ODK_S7STRING TraceBuffer[256][127])

#endif