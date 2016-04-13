#include <stdio.h>

#define ASIZE 256

#define max(a,b) \
  ({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
   _a > _b ? _a : _b; })

const char *bm_strstr(const char *needle, int neel, const char *haystack, int hayl);
