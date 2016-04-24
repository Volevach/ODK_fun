/*
 * This file is AUTO GENERATED - DO NOT MODIFY this file. 
 * This file contains the function prototypes of ODK 1500S.
 *
 * File created by ODK_CodeGenerator version 200.0.2304.1
 * at Sun April 24 18:14:54 2016 
*/

#if !defined    ODK_Functions_H
#define ODK_Functions_H

#include "ODK_Types.h"

#ifdef DLL_EXPORT
  #define EXPORT_API extern "C" __declspec(dllexport)
#else
  #define EXPORT_API extern "C"
#endif

// perform a 1024 point fast fourier transformation                       
ODK_RESULT FFT1024p (
  /*IN*/const ODK_INT16 timeCoef[1024], // time domain coefficients
  /*OUT*/Complex freqCoef[1024]); // frequency domain coefficients
#define _ODK_FUNCTION_FFT1024P  ODK_RESULT FFT1024p (/*IN*/const ODK_INT16 timeCoef[1024], /*OUT*/Complex freqCoef[1024])

// multiply complex coeffs with a filter function                        
ODK_RESULT LP_Filter (
  /*IN*/const Complex freqCoef[1024], // filter input
  /*OUT*/Complex freqCoefFilt[1024]); // filter output
#define _ODK_FUNCTION_LP_FILTER  ODK_RESULT LP_Filter (/*IN*/const Complex freqCoef[1024], /*OUT*/Complex freqCoefFilt[1024])

// perform an inverse 1024 point fast fourier transformation                   
ODK_RESULT IFFT1024p (
  /*IN*/const Complex freqCoef[1024], // frequency domain coefficients
  /*OUT*/ODK_INT16 timeCoefOut[1024]); // time domain coefficients
#define _ODK_FUNCTION_IFFT1024P  ODK_RESULT IFFT1024p (/*IN*/const Complex freqCoef[1024], /*OUT*/ODK_INT16 timeCoefOut[1024])

// perform a full filter with FFT->Filter->IFFT
ODK_RESULT FFT_Filt (
  /*IN*/const ODK_INT16 timeCoef[1024], // time domain input coefficients
  /*OUT*/ODK_INT16 timeCoefOut[1024]); // time domain output coefficients
#define _ODK_FUNCTION_FFT_FILT  ODK_RESULT FFT_Filt (/*IN*/const ODK_INT16 timeCoef[1024], /*OUT*/ODK_INT16 timeCoefOut[1024])

ODK_RESULT GetTrace (
  /*IN*/const ODK_INT16& TraceCount,
  /*OUT*/ODK_S7STRING TraceBuffer[256][127]);
#define _ODK_FUNCTION_GETTRACE  ODK_RESULT GetTrace (/*IN*/const ODK_INT16& TraceCount, /*OUT*/ODK_S7STRING TraceBuffer[256][127])

#endif