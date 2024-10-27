#include <stdio.h>

#define to_lower(c)    (char) ((c >= 'A' && c <= 'Z') ? (c | 0x20) : c)

int strlength(char *s)
{
  int i;

  i = 0;
  while (s[i] != '\0')
    ++i;
  return (i);
}

int i_power(int x, int y)
{
  int result = 1;
  while (1) {
    if (y & 1)
      result *= x;
    y = y >> 1;
    if (!y) break;
    x *= x;
  }
  return (result);
}

int is_hex(char *s, int len)
{
  for (int i = 0; i < len; ++i)
  {
    if (s[i] == '0' && to_lower(s[i + 1]) == 'x')
      return (1);
  }
  return (0);
}

int htoi(char *s)
{
  int i, n, len, curr_num;

  len = strlength(s);
  if (!is_hex(s, len))
    return (0);
  n = 0;
  for (i = len - 1; to_lower(s[i]) != 'x'; --i) {
    curr_num = 0;
    if (s[i] >= '0' && s[i] <= '9') {
      curr_num = s[i] - '0';
    } else {
      switch (to_lower(s[i])) {
        case 'a': curr_num = 10; break;
        case 'b': curr_num = 11; break;
        case 'c': curr_num = 12; break;
        case 'd': curr_num = 13; break;
        case 'e': curr_num = 14; break;
        case 'f': curr_num = 15; break;
        default: return (0);
      }
    }
    n += curr_num * i_power(16, len - 1 - i);
  }
  return (n);
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    printf("ERROR: too few argumnets\n");
    return (1);
  }
  printf("input : %s\n", argv[1]);
  printf("output : %d\n", htoi(argv[1]));
  return (0);
}
