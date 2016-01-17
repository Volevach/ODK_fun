/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the execute function and the string helpers for ODK 1500S.
 *
 * File created by ODK_CodeGenerator version 2.0.0.0
 * at Sun January 17 16:46:33 2016
*/

#include "ODK_Functions.h"

#define ODK_COMMAND_NOT_IMPLEMENTED    0x8098 
ODK_UINT32 g_ODK1500sBuildVersion = (2 << 24) + (0 << 16) + (0 << 8) + 0;
//command enums
typedef enum CommandHash_e
{
  FCT_HASH_WaveSetup = 0x957261D2,
  FCT_HASH_GetSamplesStereo = 0x5138CB06,
  FCT_HASH_WriteSamples = 0xB31777CF
}CommandHash_t;

//Execute()
EXPORT_API ODK_RESULT Execute (ODK_UINT32        cmd
                              ,const char* const in
                              ,const char*       inout
                              ,const char*       out)
{
  switch (cmd)
  {
    case FCT_HASH_WaveSetup:
    {
      return WaveSetup ((ODK_S7STRING*) &(in[0]), (ODK_S7STRING*) &(in[256]));
    }
    case FCT_HASH_GetSamplesStereo:
    {
      return GetSamplesStereo ((ODK_INT8*) &(out[0]), (ODK_INT8*) &(out[1024]));
    }
    case FCT_HASH_WriteSamples:
    {
      return WriteSamples ((ODK_INT8*) &(in[0]), (ODK_INT8*) &(in[1024]));
    }
    default:
    {
      return ODK_COMMAND_NOT_IMPLEMENTED;
    }
  }
}


