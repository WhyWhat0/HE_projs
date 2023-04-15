#include "Header.h"

#define _min(a,b) a<b?a:b
#define _max(a,b) a>b?a:b
#define swap(a)( a >> (sizeof(a)*4) | a << (sizeof(a)*4))
#define high(a)( a >> (sizeof(a)*4) << (sizeof(a)*4))
#define low(a)( a << (sizeof(a)*4) >> (sizeof(a)*4))