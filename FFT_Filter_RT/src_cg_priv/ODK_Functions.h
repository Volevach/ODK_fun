/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the function prototypes the user defined.
 *
 * File created by ODK_CodeGenerator version 200.0.1202.1
 * at Sat January 9 00:28:23 2016 
*/

#if !defined    ODK_Functions_H 
#define ODK_Functions_H

#include "ODK_Types.h"

#ifdef DLL_EXPORT
  #define EXPORT_API extern "C" __declspec(dllexport)
#else
  #define EXPORT_API extern "C"
#endif

// Basic function in order to show 
// how to create a function in ODK 1500S.
ODK_RESULT SampleFunction (
  /*IN*/ const ODK_INT32& myInt,// integer value as input
  /*OUT*/ ODK_BOOL& myBool,// bool value as output
  /*INOUT*/ ODK_DOUBLE& myReal// double value as input and output
);
#define ODK_FUNCTION_SAMPLEFUNCTION  ODK_RESULT SampleFunction (/*IN*/ const ODK_INT32& myInt, /*OUT*/ ODK_BOOL& myBool, /*INOUT*/ ODK_DOUBLE& myReal)

ODK_RESULT FFT1024p (
  /*IN*/ const ODK_UINT8& timeCoef,// time domain coefficients
  /*OUT*/ ODK_FLOAT& freqCoefRe,// real frequency domain coefs
  /*OUT*/ ODK_FLOAT& freqCoefIm// imaginary frequency domain coefs
);
#define ODK_FUNCTION_FFT1024P  ODK_RESULT FFT1024p (/*IN*/ const ODK_UINT8& timeCoef, /*OUT*/ ODK_FLOAT& freqCoefRe, /*OUT*/ ODK_FLOAT& freqCoefIm)

ODK_RESULT GetTrace (
  /*IN*/ const ODK_INT16& TraceCount,
  /*OUT*/ ODK_S7STRING TraceBuffer[256][127]
);
#define ODK_FUNCTION_GETTRACE  ODK_RESULT GetTrace (/*IN*/ const ODK_INT16& TraceCount, /*OUT*/ ODK_S7STRING TraceBuffer[256][127])

#endif





