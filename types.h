#ifndef __MRT_TYPES_H__
#define __MRT_TYPES_H__ 1


#if defined (__USE_SSE__)
#include <x86intrin.h>


//typedef float v4sf __attribute__ ((vector_size(16)));
//typedef v4sf vec4_t;

typedef __m128 vec4_t;

#define __CALL_VEC__(fn, r, a...) r=fn(a)
#define __PROTO_VEC(fn, r_type, a_type...) inline r_type fn(a_type)


#else /* NO SSE */

typedef float vec4_t [4];

#define __CALL_VEC__(fn, r, a...) fn(r, a)
#define __PROTO_VEC(fn, r_type, a_type...) inline void fn(r_type result, a_type)

#endif /* NO SSE */

#endif /* __MRT_TYPES_H__ */
