#ifndef ODK_STRINGHELPER_H
#define ODK_STRINGHELPER_H

#include "ODK_Types.h"
#include <string.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C"
{
#endif
//
// Converts PLC string type to C/C++ string type char array
// returns -1 if maxDestLen <= length of source buffer or the count of copied characters.
//
int Convert_S7STRING_to_SZSTR(const ODK_S7STRING* const src, // PLC type string to be copied to destination string
                              char* dest,                    // C/C++ type string(char array) which the source is going to be copied into
                              const int maxDestLen);         // Maximum size of destination buffer. It must also include the null termination character.

//
// Converts  C/C++ string type char array to PLC string type
// returns -1 if length of destination < length of source .or the count of copied characters.
//
int Convert_SZSTR_to_S7STRING(const char* const src, // C/C++ type string(char array) which is going to be copied to destination string
                              ODK_S7STRING* dest);   // PLC type string  which the source is going to be copied into

//
// Gets the current length of a PLC string type.
//
int Get_S7STRING_Length(const ODK_S7STRING* const src);

//
// Gets the maximum length of a PLC string type.
//
int Get_S7STRING_MaxLength(const ODK_S7STRING* const src);

#ifdef __cplusplus
}
#endif

#endif