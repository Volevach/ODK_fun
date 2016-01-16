#include "ODK_StringHelper.h"

int Convert_S7STRING_to_SZSTR(const ODK_S7STRING* const src,  char* dest, const int maxDestLen)
{
    int ret = -1;
    int currentLen = src[1];

    if (currentLen < maxDestLen)
    {
        memcpy(dest, &(src[2]), currentLen); 
        dest[currentLen] = '\0';
        ret = currentLen;
    }
    return ret;
}

int Convert_SZSTR_to_S7STRING(const char* const src, ODK_S7STRING* dest)
{
    int ret = -1;
    size_t currentLen = strlen(src);

    if (dest[0] >= currentLen)
    {
        memcpy(&(dest[2]), src, currentLen);
        dest[1] = (ODK_S7STRING) currentLen;
        ret = dest[1];
    }
    return ret;
}

int Get_S7STRING_Length(const ODK_S7STRING* const src)
{
    return src[1];
}

int Get_S7STRING_MaxLength(const ODK_S7STRING* const src)
{
    return src[0];
}

