/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the function prototypes the user defined.
 *
 * File created by ODK_CodeGenerator version 2.0.0.0
 * at Sun January 31 20:03:01 2016 
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
  /*OUT*/ Complex freqCoef[1024]// frequency domain coefficients
);
#define _ODK_FUNCTION_FFT1024P  ODK_RESULT FFT1024p (/*IN*/ const ODK_INT16 timeCoef[1024], /*OUT*/ Complex freqCoef[1024])

ODK_RESULT LP_Filter (
  /*IN*/ const Complex freqCoef[1024],// filter input
  /*OUT*/ Complex freqCoefFilt[1024]// filter output
);
#define _ODK_FUNCTION_LP_FILTER  ODK_RESULT LP_Filter (/*IN*/ const Complex freqCoef[1024], /*OUT*/ Complex freqCoefFilt[1024])

ODK_RESULT IFFT1024p (
  /*IN*/ const Complex freqCoef[1024],// frequency domain coefficients
  /*OUT*/ ODK_INT16 timeCoefOut[1024]// time domain coefficients
);
#define _ODK_FUNCTION_IFFT1024P  ODK_RESULT IFFT1024p (/*IN*/ const Complex freqCoef[1024], /*OUT*/ ODK_INT16 timeCoefOut[1024])

ODK_RESULT FFT_Filt (
  /*IN*/ const ODK_INT16 timeCoef[1024],// time domain input coefficients
  /*OUT*/ ODK_INT16 timeCoefOut[1024]// time domain output coefficients
);
#define _ODK_FUNCTION_FFT_FILT  ODK_RESULT FFT_Filt (/*IN*/ const ODK_INT16 timeCoef[1024], /*OUT*/ ODK_INT16 timeCoefOut[1024])


#endif





