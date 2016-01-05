/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the function prototypes the user defined.
 *
 * File created by ODK_CodeGenerator version 101.0.902.1
 * at Wed January 6 00:08:23 2016 
*/

#if !defined    ODK_Functions_H
#define ODK_Functions_H

#include "ODK_Types.h"

#ifdef DLL_EXPORT
  #define EXPORT_API extern "C" __declspec(dllexport)
#else
  #define EXPORT_API extern "C"
#endif
ODK_RESULT SampleFunction (const ODK_INT32& myInt, ODK_BOOL& myBool, ODK_DOUBLE& myReal);

ODK_RESULT GetTrace (const ODK_INT16& TraceCount, ODK_S7STRING TraceBuffer[256][127]);

#endif // GetHashPrototype

