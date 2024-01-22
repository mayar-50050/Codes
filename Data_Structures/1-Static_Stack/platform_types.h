#ifndef _PLATFORM_TYPES_H_
#define _PLATFORM_TYPES_H_
////////////////////////////////////////////////////////////////////////
/*              Platforms types pased on number of bits               */
#define TARGET_8_BIT   8
#define TARGET_16_BIT  16
#define TARGET_32_BIT  32
#define TARGET_64_BIT  64

#define SYSTEM_TYPE     TARGET_64_BIT
////////////////////////////////////////////////////////////////////////
/*                      8 bit data types                              */
#if (SYSTEM_TYPE==TARGET_8_BIT)
typedef unsigned char         boolean;
typedef unsigned char         uint8;
typedef unsigned short        uint16;
typedef unsigned long         uint32;

typedef signed char           sint8;
typedef signed short          sint16;
typedef signed long           sint32;

typedef float                 float32;

//////////////////////////////////////////////////////////////////////
/*                      64 bit data types                           */
#elif (SYSTEM_TYPE==TARGET_64_BIT)
typedef unsigned char         boolean;
typedef unsigned char         uint8;
typedef unsigned short        uint16;
typedef unsigned int          uint32; /*Long = INT */
typedef unsigned long long    uint64;

typedef signed char           sint8;
typedef signed short          sint16;
typedef signed int            sint32;
typedef signed long long      sint64;

typedef float                 float32;
typedef double                float64;

//////////////////////////////////////////////////////////////////////
/*                      16 bit data types                           */
#elif (SYSTEM_TYPE==TARGET_16_BIT)
typedef unsigned char         boolean;

//////////////////////////////////////////////////////////////////////
/*                      32 bit data types                           */
#else /*(SYSTEM_TYPE==TARGET_32_BIT)*/
typedef unsigned char         boolean;
typedef unsigned char         uint8;
typedef unsigned short        uint16;
typedef unsigned int          uint32;   ///*Long = INT */

typedef signed char           sint8;
typedef signed short          sint16;
typedef signed int            sint32;

typedef float                 float32;

#endif


#endif /*_PLATFORM_TYPES_H_*/
