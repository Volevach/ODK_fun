/* 
 * This file ALWAYS GENERATED - DO NOT MOTIFY this file. 
 * This file contains the elementary data types of ODK 1500S.
 *
 * File created by ODK_CodeGenerator version 2.0.0.0 
 * at Sun January 17 22:46:35 2016 
 */

#if !defined ODK_Types_H
#define ODK_Types_H

#define ODK_TRACE_ON 
#ifdef ODK_TRACE_ON
  #define ODK_TRACE(msg, ...) ODK_Trace(__FILE__, __LINE__, msg, ##__VA_ARGS__)
#else
  #define ODK_TRACE(msg, ...)
#endif

void ODK_Trace(const char* p_szFileName, const int p_nLine, const char* p_szMsg, ...);

#define  ODK_SUCCESS         0x0000
#define  ODK_TRUE            1
#define  ODK_FALSE           0

typedef  double              ODK_DOUBLE;
typedef  float               ODK_FLOAT;
typedef  long long           ODK_INT64;
typedef  long                ODK_INT32;
typedef  short               ODK_INT16;
typedef  char                ODK_INT8;
typedef  unsigned long long  ODK_UINT64;
typedef  unsigned long       ODK_UINT32;
typedef  unsigned short      ODK_UINT16;
typedef  unsigned char       ODK_UINT8;
typedef  unsigned long long  ODK_LWORD;
typedef  unsigned long       ODK_DWORD;
typedef  unsigned short      ODK_WORD;
typedef  unsigned char       ODK_BYTE;
typedef  unsigned char       ODK_BOOL;
typedef  unsigned long long  ODK_LTIME;
typedef  unsigned long       ODK_TIME;
typedef  unsigned long long  ODK_LDT;
typedef  unsigned long long  ODK_LTOD;
typedef  unsigned long       ODK_TOD;
typedef  unsigned char       ODK_S7STRING;
typedef  char                ODK_CHAR;
typedef  unsigned short      ODK_RESULT;


#pragma pack(push,1)
typedef struct ODK_DTL_s
{
  ODK_UINT16      Year;
  ODK_UINT8       Month;
  ODK_UINT8       Day;
  ODK_UINT8       Weekday;
  ODK_UINT8       Hour;
  ODK_UINT8       Minute;
  ODK_UINT8       Second;
  ODK_UINT32      Nanosecond;
} ODK_DTL;

// CLASSIC_DB
typedef struct ODK_CLASSIC_DB_s
{
  ODK_UINT32    Len;
  ODK_UINT8     Data[1];
} ODK_CLASSIC_DB;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct
{
  ODK_FLOAT re;
  ODK_FLOAT im;
}complex;
#pragma pack(pop)

#endif // ODK_Types_H