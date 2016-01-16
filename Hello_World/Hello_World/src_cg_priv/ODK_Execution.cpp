/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the execute function and the string helpers for ODK 1500S.
 *
 * File created by ODK_CodeGenerator version 2.0.0.0
 * at Sat January 16 23:20:21 2016
*/

#include "ODK_Functions.h"

#define ODK_COMMAND_NOT_IMPLEMENTED    0x8098 
ODK_UINT32 g_ODK1500sBuildVersion = (2 << 24) + (0 << 16) + (0 << 8) + 0;
//command enums
typedef enum CommandHash_e
{
  FCT_HASH_HelloWorld_Win32 = 0x81B679C7
}CommandHash_t;

//Execute()
EXPORT_API ODK_RESULT Execute (ODK_UINT32        cmd
                              ,const char* const in
                              ,const char*       inout
                              ,const char*       out)
{
  switch (cmd)
  {
    case FCT_HASH_HelloWorld_Win32:
    {
      return HelloWorld_Win32 ((ODK_S7STRING*) &(in[0]), (ODK_S7STRING*) &(inout[0]));
    }
    default:
    {
      return ODK_COMMAND_NOT_IMPLEMENTED;
    }
  }
}


