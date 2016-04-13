#include <stdio.h>
#include <string.h>
#include "substr.h"

#define RESET           "\033[0m"
#define BOLDRED         "\033[1m\033[31m"
#define BOLDGREEN       "\033[1m\033[32m"

static unsigned char nb_test = 0;
static unsigned char nb_error = 0;

static int my_strcmp(const char *p1, const char *p2)
{
  if (p1 == NULL && p2 == NULL)
    return 0;

  if (p1 == NULL || p2 == NULL)
    return 1;

  return strcmp(p1, p2);
}

static void test(char *pattern, char *str)
{
  const char *str1 = bm_strstr(pattern, strlen(pattern), str, strlen(str));
  const char *str2 = strstr(str, pattern);
  nb_test += 1;

  if (my_strcmp(str1, str2))
  {
    printf("Test n°%u\t\t[  " BOLDRED "K0" RESET "  ]\n", nb_test);
    printf("\tExpected :\t");
    if (str2 == NULL)
      printf("NULL\n");
    else
      printf("%s\n", str2);
    printf("\tAnd got :\t");
    if (str1 == NULL)
      printf("NULL\n");
    else
      printf("%s\n", str1);
    nb_error += 1;
  }
  else
  {
    printf("Test n°%u\t\t[  " BOLDGREEN "OK" RESET "  ]\n", nb_test);
  }

}

int main(void)
{
  /* Add Test here */
  test("world", "Hello world");
  test("Hello world", "Hello world");
  test("GCAGAGAG", "GCGCAGAGAGTGATCGCAGAGAGTATACAGTACG");
  test("GGCAGAGAGGCAGAGAGGCAGAGAGCAGAGAG", "GCGCAGAGAGTGATCGCAGAGAGTATACAGTACG");

  /* Recap */
  if (nb_error)
  {
    printf("\n%u Tests  : " BOLDRED "%u" RESET " error(s)\n", nb_test, nb_error);
    printf("Fix this!\n\n");
  }
  else
  {
    printf("\n%u Tests  : " BOLDGREEN "%u" RESET " error(s)\n", nb_test, nb_error);
    printf("Cool!\n");
  }

  return nb_error;
}
