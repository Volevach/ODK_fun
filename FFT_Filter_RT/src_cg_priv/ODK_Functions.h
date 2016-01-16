/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the function prototypes the user defined.
 *
 * File created by ODK_CodeGenerator version 2.0.0.0
 * at Sat January 16 21:14:08 2016 
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
  /*IN*/ const ODK_INT16 timeCoef[1024],// time domain coefficients
  /*OUT*/ ODK_FLOAT freqCoefRe[1024],// real frequency domain coefs
  /*OUT*/ ODK_FLOAT freqCoefIm[1024]// imaginary frequency domain coefs
);
#define _ODK_FUNCTION_FFT1024P  ODK_RESULT FFT1024p (/*IN*/ const ODK_INT16 timeCoef[1024], /*OUT*/ ODK_FLOAT freqCoefRe[1024], /*OUT*/ ODK_FLOAT freqCoefIm[1024])

ODK_RESULT LP_Filter (
  /*IN*/ const ODK_FLOAT inRe[1024],// time domain coefficients
  /*IN*/ const ODK_FLOAT inIm[1024],// time domain coefficients
  /*OUT*/ ODK_FLOAT outRe[1024],// real frequency domain coefs
  /*OUT*/ ODK_FLOAT outIm[1024]// imaginary frequency domain coefs
);
#define _ODK_FUNCTION_LP_FILTER  ODK_RESULT LP_Filter (/*IN*/ const ODK_FLOAT inRe[1024], /*IN*/ const ODK_FLOAT inIm[1024], /*OUT*/ ODK_FLOAT outRe[1024], /*OUT*/ ODK_FLOAT outIm[1024])

ODK_RESULT IFFT1024p (
  /*IN*/ const ODK_FLOAT freqCoefRe[1024],// real frequency domain coefs
  /*IN*/ const ODK_FLOAT freqCoefIm[1024],// imaginary frequency domain coefs
  /*OUT*/ ODK_INT16 timeCoef[1024]// time domain coefficients
);
#define _ODK_FUNCTION_IFFT1024P  ODK_RESULT IFFT1024p (/*IN*/ const ODK_FLOAT freqCoefRe[1024], /*IN*/ const ODK_FLOAT freqCoefIm[1024], /*OUT*/ ODK_INT16 timeCoef[1024])

ODK_RESULT GetTrace (
  /*IN*/ const ODK_INT16& TraceCount,
  /*OUT*/ ODK_S7STRING TraceBuffer[256][127]
);
#define _ODK_FUNCTION_GETTRACE  ODK_RESULT GetTrace (/*IN*/ const ODK_INT16& TraceCount, /*OUT*/ ODK_S7STRING TraceBuffer[256][127])

#endif





