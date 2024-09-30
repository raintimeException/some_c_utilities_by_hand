#include <stdio.h>

#define SIZE_ARR 10

char *foo(void);
void bar(char *arr[static SIZE_ARR]);

int main(void)
{
  char *name;
  char *names[SIZE_ARR];
  for (int i = 0; i < SIZE_ARR; ++i)
    names[i] = foo();
  bar(names);
  return(0);
}

void bar(char *arr[static SIZE_ARR])
{
  printf("bar is called\n");
  for (int i = 0; i < SIZE_ARR; ++i)
    printf("the name in the position %i is %s\n", i, arr[i]);
}

char *foo(void)
{
    static char *name_to_give = "ivan";
    return(name_to_give);
}
