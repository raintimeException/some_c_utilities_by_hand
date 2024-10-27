#include <stdio.h>

/*
 * An alternative version of squeeze(s1, s2) that deletes each character
 * in s1 that matches any character in the string s2
 */
void squeeze(char s1[], char s2[])
{
  for (int i = 0; s1[i] != '\0'; ++i)
    for (int j = 0; s2[j] != '\0'; ++j)
      if (s1[i] == s2[j])
        for (int k = i; s1[k] != '\0'; ++k)
          s1[k] = s1[k + 1];
}

int main(void)
{
  char s1[] = "abcdf";
  char s2[] = "cd";
  squeeze(s1, s2);
  printf("%s : %s\n", s1, s2);
  return (0);
}
