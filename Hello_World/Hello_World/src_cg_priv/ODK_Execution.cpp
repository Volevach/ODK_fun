/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the execute function and the string helpers for ODK 1500S.
 *
 * File created by ODK_CodeGenerator version 200.0.1202.1
 * at Sun January 10 19:51:27 2016
*/

#include "ODK_Functions.h"

#define ODK_COMMAND_NOT_IMPLEMENTED    0x8098 

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


