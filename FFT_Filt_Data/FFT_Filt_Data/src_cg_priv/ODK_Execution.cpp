/*
 * This file is ALWAYS GENERATED - DO NOT MODIFY this file.
 * This file contains the execute function and the string helpers for ODK 1500S.
 *
 * File created by ODK_CodeGenerator version 2.0.0.0
 * at Sun January 17 17:54:04 2016
*/

#include "ODK_Functions.h"

#define ODK_COMMAND_NOT_IMPLEMENTED    0x8098 
ODK_UINT32 g_ODK1500sBuildVersion = (2 << 24) + (0 << 16) + (0 << 8) + 0;
//command enums
typedef enum CommandHash_e
{
  FCT_HASH_WaveSetup = 0x957261D2,
  FCT_HASH_GetSamplesStereo = 0xBAEFE192,
  FCT_HASH_WriteSamples = 0x9EA4D02E
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
      return GetSamplesStereo ((ODK_INT16*) &(out[0]), (ODK_INT16*) &(out[2048]), *((ODK_BOOL*) &(out[4096])));
    }
    case FCT_HASH_WriteSamples:
    {
      return WriteSamples ((ODK_INT16*) &(in[0]), (ODK_INT16*) &(in[2048]));
    }
    default:
    {
      return ODK_COMMAND_NOT_IMPLEMENTED;
    }
  }
}


