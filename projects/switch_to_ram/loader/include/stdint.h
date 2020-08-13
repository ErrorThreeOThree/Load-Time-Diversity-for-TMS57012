#ifndef STDINT
#define STDINT

/*******************************************************************************
 * THIS IS NOT A FULL stdint.h IMPLEMENTATION - It only contains the definitions
 * necessary to build the FreeRTOS code.  It is provided to allow FreeRTOS to be
 * built using compilers that do not provide their own stdint.h definition.
 *
 * To use this file:
 *
 *    1) Copy this file into the directory that contains your FreeRTOSConfig.h
 *       header file, as that directory will already be in the compilers include
 *       path.
 *
 *    2) Rename the copied file stdint.h.
 *
 */

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef unsigned short uint16;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef unsigned int uint32;
typedef unsigned long long uint64_t;
typedef unsigned long long uint64;
typedef long int int64_t;

#endif /* STDINT */
