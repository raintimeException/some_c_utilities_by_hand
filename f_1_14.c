#include <stdio.h>

#define COUT_CHARS  26+26

/* program to print a histogram of the frequencies of diferent
 * characters in its input */
int main(void)
{
  int c, chars_visual[COUT_CHARS], chars_histogram[COUT_CHARS];

  for (int i = 0; i < COUT_CHARS; ++i)
  {
    chars_visual[i]    = 0;
    chars_histogram[i] = 0;
  }

  for (int i = 65, pos = 0; pos < COUT_CHARS && i < 123; ++i, ++pos)
  {
    if (i <= 90 || i >= 97)
      chars_visual[pos] = i;
    else
      --pos;
  }
  while ((c = getchar()) != EOF)
  {
    if ((c >= 65 && c <= 90) || (c >= 97 && c < 123))
    {
      for (int i = 0; i < COUT_CHARS; ++i)
      {
        if (chars_visual[i] == c)
          ++chars_histogram[i];
      }
    }
  }
  for (int i = 0; i < COUT_CHARS; ++i)
  {
    printf("\n%c %d", chars_visual[i], chars_histogram[i]);
    for (int j = 0; j < chars_histogram[i]; ++j)
      printf("*");
  }
  return(0);
}
