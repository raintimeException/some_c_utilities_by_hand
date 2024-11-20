#include <stdio.h>
#include <stdarg.h>

#define MAXARGS 99

union {
        int *d;
        double *f;
        char *s;
        unsigned int *ud;
        long *ld;
} type;

void minscanf(char *fmt, ...)
{
        va_list ap;
        char *p;
        int c;

        va_start(ap, fmt);
        for (p = fmt; *p; p++) {
                if (*p != '%') continue;
                switch (*++p) {
                        case 'd':
                                type.d = va_arg(ap, int *);
                                scanf("%d", type);
                                break;
                        case 'l':
                                if (*++p == 'd') {
                                        type.ld = va_arg(ap, long int *);
                                        scanf("%ld", type);
                                }
                                else if (*p == 'f') {
                                        type.f = va_arg(ap, double *);
                                        scanf("%lf", type);
                                }
                                break;
                        case 'u':
                                type.ud = va_arg(ap, unsigned int *);
                                scanf("%u", type);
                                break;
                        case 's':
                                for (type.s = va_arg(ap, char *); scanf("%s", type.s) != EOF ;)
                                        ;
                                break;
                        default:
                                printf("error: not supported\n");
                                break;
                }
        }
}

int main(void)
{
        char *fmt = "%d";
        int i = 0;
        minscanf(fmt, &i);
        printf("%d\n", i);
        return 0;
}
