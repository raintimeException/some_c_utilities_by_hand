#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main(void)
{
        int type;
        double op2;
        char s[MAXOP];

        while ((type = getop(s)) != EOF) {
                switch (type) {
                        case NUMBER:
                                push(atof(s));
                                break;
                        case '+':
                                push(pop() + pop());
                                break;
                        case '*':
                                push(pop() * pop());
                                break;
                        case '-':
                                op2 = pop();
                                push(pop() - op2);
                                break;
                        case '/':
                                op2 = pop();
                                if (op2 == 0)
                                        printf("error: division by zero\n");
                                else
                                        push(pop() / op2);
                                break;
                        case '\n':
                                printf("\t%.8f\n", pop());
                                break;
                        default:
                                printf("error: unknown command %s\n", s);
                                break;
                }
        }
        return (0);
}

