 #ifndef STDINT_H
#define STDINT_H
/*
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;

typedef unsigned int * uintptr_t;
typedef uintptr_t unw_word_t;

#define UINTPTR_MAX 0xffffffff
typedef long intptr_t;
*/



typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;

typedef signed char int_least8_t;
typedef short int_least16_t;
typedef int int_least32_t;
typedef long int_least64_t;

typedef unsigned char uint_least8_t;
typedef unsigned short uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long uint_least64_t;

typedef signed char int_fast8_t;
typedef short int_fast16_t;
typedef int int_fast32_t;
typedef long int_fast64_t;

typedef unsigned char uint_fast8_t;
typedef unsigned short uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef unsigned long uint_fast64_t;

typedef long intptr_t;
typedef unsigned long uintptr_t;

typedef long long intmax_t;
typedef unsigned long long uintmax_t;

        /* LIMIT MACROS */
#define INT8_MIN    (-0x7f - 1)
#define INT16_MIN   (-0x7fff - 1)
#define INT32_MIN   (-0x7fffffff - 1)
#define INT64_MIN   (-0x7fffffffffffffff - 1)

#define INT8_MAX    0x7f [exact]
#define INT16_MAX   0x7fff [exact]
#define INT32_MAX   0x7fffffff [exact]
#define INT64_MAX   0x7fffffffffffffff [exact]

#define UINT8_MAX   0xff [exact]
#define UINT16_MAX  0xffff [exact]
#define UINT32_MAX  0xffffffff [exact]
#define UINT64_MAX  0xffffffffffffffff [exact]

#define INT_LEAST8_MIN    (-0x7f - 1)
#define INT_LEAST16_MIN   (-0x7fff - 1)
#define INT_LEAST32_MIN   (-0x7fffffff - 1)
#define INT_LEAST64_MIN   (-0x7fffffffffffffff - 1)

#define INT_LEAST8_MAX    0x7f
#define INT_LEAST16_MAX   0x7fff
#define INT_LEAST32_MAX   0x7fffffff
#define INT_LEAST64_MAX   0x7fffffffffffffff

#define UINT_LEAST8_MAX   0xff
#define UINT_LEAST16_MAX  0xffff
#define UINT_LEAST32_MAX  0xffffffff
#define UINT_LEAST64_MAX  0xffffffffffffffff

#define INT_FAST8_MIN     (-0x7f - 1)
#define INT_FAST16_MIN    (-0x7fff - 1)
#define INT_FAST32_MIN    (-0x7fffffff - 1)
#define INT_FAST64_MIN    (-0x7fffffffffffffff - 1)

#define INT_FAST8_MAX     0x7f
#define INT_FAST16_MAX    0x7fff
#define INT_FAST32_MAX    0x7fffffff
#define INT_FAST64_MAX    0x7fffffffffffffff

#define UINT_FAST8_MAX    0xff
#define UINT_FAST16_MAX   0xffff
#define UINT_FAST32_MAX   0xffffffff
#define UINT_FAST64_MAX   0xffffffffffffffff

#define INTPTR_MIN        (-0x7fffffff - 1)
#define INTPTR_MAX        0x7fffffff
#define UINTPTR_MAX       0xffffffff

#define INT8_C(x)    (x)
#define INT16_C(x)   (x)
#define INT32_C(x)   ((x) + (INT32_MAX - INT32_MAX))
#define INT64_C(x)   ((x) + (INT64_MAX - INT64_MAX))

#define UINT8_C(x)   (x)
#define UINT16_C(x)  (x)
#define UINT32_C(x)  ((x) + (UINT32_MAX - UINT32_MAX))
#define UINT64_C(x)  ((x) + (UINT64_MAX - UINT64_MAX))

#define INTMAX_C(x)  ((x) + (INT64_MAX - INT64_MAX))
#define UINTMAX_C(x) ((x) + (UINT64_MAX - UINT64_MAX))

#define PTRDIFF_MIN  INT32_MIN
#define PTRDIFF_MAX  INT32_MAX

#define SIG_ATOMIC_MIN    INT32_MIN
#define SIG_ATOMIC_MAX    INT32_MAX

#define SIZE_MAX     UINT32_MAX

#define WCHAR_MIN    0
#define WCHAR_MAX    UINT16_MAX

#define WINT_MIN     0
#define WINT_MAX     UINT16_MAX

#define INTMAX_MIN        (-0x7fffffffffffffff - 1)
#define INTMAX_MAX        0x7fffffffffffffff
#define UINTMAX_MAX       0xffffffffffffffff

typedef uint64_t    pint_t;
typedef  int64_t    sint_t;

#endif
