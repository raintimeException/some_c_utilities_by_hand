#include <stdio.h>

#define MAX_LEN 1024

int _getline(char line[], int lim);
int _strlen(char line[]);
void _reverse(char line[]);

int main(void)
{
  char line[MAX_LEN];

  while (_getline(line, MAX_LEN) > 0)
  {
    _reverse(line);
    printf("%s\n", line);
  }
  return(0);
}

void _reverse(char line[])
{
  int i;
  int pos = -1;
  int len = _strlen(line);
  char temp[MAX_LEN];

  for (i = 0; i < len; ++i)
    temp[++pos] = line[i];
  for (i = 0; i < len; ++i)
    line[i] = temp[--pos];
}

int _strlen(char line[])
{
  int i;

  i = 0;
  while (line[i] != '\0')
    i++;
  return(i);
}

int _getline(char line[], int lim)
{
  int i, c;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    line[i] = c;
  if (c == '\n')
  {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return(i);
}
