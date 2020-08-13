/** @file
*   @brief Header for string_custom.c
*   @date 19-06-07
*   @version 0.1
*
*  Header file with function prototypes for string_custom.c
*/
#ifndef STRING_CUSTOM_H
#define STRING_CUSTOM_H

#include "stddef.h"
#include "stdint.h"

void *memcpy_custom(void *dst, const void *src, size_t n);

void *memset_custom(void *dst, uint8_t val, size_t len);
#endif
