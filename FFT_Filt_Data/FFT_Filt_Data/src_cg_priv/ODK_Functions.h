/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the function prototypes the user defined.
 *
 * File created by ODK_CodeGenerator version 2.0.0.0
 * at Sun January 17 16:46:34 2016 
*/

#if !defined    ODK_Functions_H 
#define ODK_Functions_H

#include "ODK_Types.h"

#ifdef DLL_EXPORT
  #define EXPORT_API extern "C" __declspec(dllexport)
#else
  #define EXPORT_API extern "C"
#endif

// Setup file handles for IO operation
ODK_RESULT WaveSetup (
  /*IN*/ const ODK_S7STRING inFileName[256],// input wave
  /*IN*/ const ODK_S7STRING outFileName[256]// output to write to
);
#define _ODK_FUNCTION_WAVESETUP  ODK_RESULT WaveSetup (/*IN*/ const ODK_S7STRING inFileName[256], /*IN*/ const ODK_S7STRING outFileName[256])

// Get one filter samlple for processing   
ODK_RESULT GetSamplesStereo (
  /*OUT*/ ODK_INT8 inputSamplesL[1024],// input audio samples left
  /*OUT*/ ODK_INT8 inputSamplesR[1024]// input audio samples right
);
#define _ODK_FUNCTION_GETSAMPLESSTEREO  ODK_RESULT GetSamplesStereo (/*OUT*/ ODK_INT8 inputSamplesL[1024], /*OUT*/ ODK_INT8 inputSamplesR[1024])

// write processed sample frame into file
ODK_RESULT WriteSamples (
  /*IN*/ const ODK_INT8 filteredSamplesL[1024],// output to write to left chan
  /*IN*/ const ODK_INT8 filteredSamplesR[1024]// output to write to right chan
);
#define _ODK_FUNCTION_WRITESAMPLES  ODK_RESULT WriteSamples (/*IN*/ const ODK_INT8 filteredSamplesL[1024], /*IN*/ const ODK_INT8 filteredSamplesR[1024])

#endif




