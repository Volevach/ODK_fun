/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the function prototypes the user defined.
 *
 * File created by ODK_CodeGenerator version 1.0.0.0
 * at Mi Juni 25 10:55:44 2014 
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

#endif // ODK_Functions_H

