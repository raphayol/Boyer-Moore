#include "substr.h"

static void fill_occur_shift(const char *x, int m, int occur_shift[]) {
   int i;

   for (i = 0; i < ASIZE; ++i)
      occur_shift[i] = m;
   for (i = 0; i < m - 1; ++i)
      occur_shift[(int)x[i]] = m - i - 1;
}

static void suffix(const char *x, int m, int *suff) {
   int f, g, i;

   suff[m - 1] = m;
   g = m - 1;
   for (i = m - 2; i >= 0; --i) {
      if (i > g && suff[i + m - 1 - f] < i - g)
         suff[i] = suff[i + m - 1 - f];
      else {
         if (i < g)
            g = i;
         f = i;
         while (g >= 0 && x[g] == x[g + m - 1 - f])
            --g;
         suff[i] = f - g;
      }
   }
}

static void fill_suffix_shift(const char *x, int m, int suffix_shift[]) {
   int i, j, suff[m];

   suffix(x, m, suff);

   for (i = 0; i < m; ++i)
      suffix_shift[i] = m;
   j = 0;
   for (i = m - 1; i >= 0; --i)
      if (suff[i] == i + 1)
         for (; j < m - 1 - i; ++j)
            if (suffix_shift[j] == m)
               suffix_shift[j] = m - 1 - i;
   for (i = 0; i <= m - 2; ++i)
      suffix_shift[m - 1 - suff[i]] = m - 1 - i;
}


const char *bm_strstr(const char *x, int m, const char *haystack, int hayl)
{
   int i;
   int j = 0;
   int occur_shift[ASIZE];
   int suffix_shift[m];

   /* Preprocessing */
   fill_suffix_shift(x, m, suffix_shift);
   fill_occur_shift(x, m, occur_shift);

   /* Searching */
   while (j <= hayl - m) {
      for (i = m - 1; i >= 0 && x[i] == haystack[i + j]; --i);
      if (i < 0) {
         return haystack + j;
      }
      else
         j += max(suffix_shift[i], occur_shift[(int)haystack[i + j]] - m + 1 + i);
   }

   return NULL;
}

