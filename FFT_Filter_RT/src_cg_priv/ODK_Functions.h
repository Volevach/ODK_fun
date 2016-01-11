/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the function prototypes the user defined.
 *
 * File created by ODK_CodeGenerator version 200.0.1202.1
 * at Mon January 11 21:28:43 2016 
*/

#if !defined    ODK_Functions_H 
#define ODK_Functions_H

#include "ODK_Types.h"

#ifdef DLL_EXPORT
  #define EXPORT_API extern "C" __declspec(dllexport)
#else
  #define EXPORT_API extern "C"
#endif

ODK_RESULT FFT1024p (
  /*IN*/ const ODK_UINT16 timeCoef[1024],// time domain coefficients
  /*OUT*/ ODK_FLOAT freqCoefRe[1024],// real frequency domain coefs
  /*OUT*/ ODK_FLOAT freqCoefIm[1024]// imaginary frequency domain coefs
);
#define ODK_FUNCTION_FFT1024P  ODK_RESULT FFT1024p (/*IN*/ const ODK_UINT16 timeCoef[1024], /*OUT*/ ODK_FLOAT freqCoefRe[1024], /*OUT*/ ODK_FLOAT freqCoefIm[1024])

ODK_RESULT GetTrace (
  /*IN*/ const ODK_INT16& TraceCount,
  /*OUT*/ ODK_S7STRING TraceBuffer[256][127]
);
#define ODK_FUNCTION_GETTRACE  ODK_RESULT GetTrace (/*IN*/ const ODK_INT16& TraceCount, /*OUT*/ ODK_S7STRING TraceBuffer[256][127])

#endif





