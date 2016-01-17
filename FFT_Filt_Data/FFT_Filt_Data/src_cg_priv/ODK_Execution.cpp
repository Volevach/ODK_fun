/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the execute function and the string helpers for ODK 1500S.
 *
 * File created by ODK_CodeGenerator version 2.0.0.0
 * at Sun January 17 14:07:32 2016
*/

#include "ODK_Functions.h"

#define ODK_COMMAND_NOT_IMPLEMENTED    0x8098 
ODK_UINT32 g_ODK1500sBuildVersion = (2 << 24) + (0 << 16) + (0 << 8) + 0;
//command enums
typedef enum CommandHash_e
{
  FCT_HASH_SampleFunction = 0xB93B0B58
}CommandHash_t;

//Execute()
EXPORT_API ODK_RESULT Execute (ODK_UINT32        cmd
                              ,const char* const in
                              ,const char*       inout
                              ,const char*       out)
{
  switch (cmd)
  {
    case FCT_HASH_SampleFunction:
    {
      return SampleFunction (*((ODK_INT32*) &(in[0])), *((ODK_BOOL*) &(out[0])), *((ODK_DOUBLE*) &(inout[0])));
    }
    default:
    {
      return ODK_COMMAND_NOT_IMPLEMENTED;
    }
  }
}


