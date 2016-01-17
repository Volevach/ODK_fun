/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the function prototypes the user defined.
 *
 * File created by ODK_CodeGenerator version 2.0.0.0
 * at Sun January 17 14:07:32 2016 
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
#define _ODK_FUNCTION_SAMPLEFUNCTION  ODK_RESULT SampleFunction (/*IN*/ const ODK_INT32& myInt, /*OUT*/ ODK_BOOL& myBool, /*INOUT*/ ODK_DOUBLE& myReal)

#endif





