#include "Header.h"

#define _min(a,b) a<b?a:b
#define _max(a,b) a>b?a:b
#define swap_int(a)( a >> (sizeof(a)*4) | a << (sizeof(a)*4))
#define swap_sh(a)( a >> (sizeof(a)*4) | a << (sizeof(a)*4))
#define swap_long(a)( a >> (sizeof(a)*8) | a << (sizeof(a)*8))
#define high(a) a >> (sizeof(a)*4) << (sizeof(a)*4)
#define low(a) a << (sizeof(a)*4) >> (sizeof(a)*4)