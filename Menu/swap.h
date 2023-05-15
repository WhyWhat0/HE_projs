#include "Header.h"

#define _min(a,b) a<b?a:b
#define _max(a,b) a>b?a:b
#define swap_short(a)( a >> (2*4) | a << (2*4))
#define swap_int(a)( a >> (4*4) | a << (4*4))
#define swap_long(a)( a >> (8*4) | a << (8*4))
#define high(a)(a << (sizeof(a)*4) >> (sizeof(a)*4) << (sizeof(a)*4) >> (sizeof(a)*4))
#define low(a)( a >> (sizeof(a)*4))
#define high_s(a) ( a << 8)
 