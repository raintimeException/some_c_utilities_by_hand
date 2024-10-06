#include <stdio.h>

#define MAX_WORD_SIZE	10

int is_space(char c)
{
  return(c == ' ' || c == '\t' || c == '\n');
}

int main(void)
{
  int c, i, j, len;
  int histogram[MAX_WORD_SIZE];

  for (i = 0; i < MAX_WORD_SIZE; ++i)
    histogram[i] = 0;

  len = 0;
  while ((c = getchar()) != EOF)
  {
    if (!is_space(c))
      ++len;
    else
    {
      ++histogram[len];
      len = 0;
    }
    putchar(c);
  }
  printf("*");
  for (i = 0; i < MAX_WORD_SIZE; ++i)
  {
    printf("\n");
    for (j = histogram[i]; j > 0; --j)
    {
      printf("-");
    }
  }
  printf("\n*\n");
  return(0);
}
