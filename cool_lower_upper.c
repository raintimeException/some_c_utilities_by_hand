#include <stdio.h>

#define to_lower(c)    (char) ((c >= 'A' && c <= 'Z') ? (c | 0x20) : c)
#define to_upper(c)    (char) ((c >= 'a' && c <= 'z') ? (c & ~0x20) : c)

int main(void)
{
  char c = 'a';
  printf("%c %d\n", c, c);
  c = to_lower(c);
  printf("%c %d\n", c, c);
  c = to_upper(c);
  printf("%c %d\n", c, c);
  return(0);
}
