#include <stdlib.h>
#include <stdio.h>

#define MAX 1000

double stack[MAX];
int pstack = 0;

double pop(void)
{
        if (pstack > 0) {
                return stack[--pstack];
        } else {
                printf("error: the stack is empty\n");
                return 0.0;
        }
}

void push(double v)
{
        if (pstack < MAX)
                stack[pstack++] = v;
        else
                printf("error: stack is full\n");
}

int main(int argc, char **argv)
{
        int sec_op, c;

        while (--argc > 0) {
                char c = **++argv;
                if (c == '+') {
                        push(pop() + pop());
                } else if (c == '*') {
                        push(pop() * pop());
                } else if (c == '-') {
                        sec_op = pop();
                        push(pop() - sec_op);
                } else if (c == '/') {
                        sec_op = pop();
                        if (sec_op != 0)
                                push(pop() / sec_op);
                        else {
                                printf("error: division by zero\n");
                                return 0;
                        }
                } else {
                        push(atof(*argv));
                }
        }
        printf("%f\n", stack[0]);
        return 0;
}
