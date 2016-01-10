/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the function prototypes the user defined.
 *
 * File created by ODK_CodeGenerator version 200.0.1202.1
 * at Sun January 10 19:51:27 2016 
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
ODK_RESULT HelloWorld_Win32 (
  /*IN*/ const ODK_S7STRING strCaption[256],
  /*INOUT*/ ODK_S7STRING strMessage[256]
);
#define ODK_FUNCTION_HELLOWORLD_WIN32  ODK_RESULT HelloWorld_Win32 (/*IN*/ const ODK_S7STRING strCaption[256], /*INOUT*/ ODK_S7STRING strMessage[256])

#endif





