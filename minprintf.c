#include <stdio.h>
#include <stdarg.h>

#define MAXARGS 99

union {
        int d;
        double f;
        char *s;
        unsigned int ud;
        long ld;
} type;

void minprintf(char *fmt, ...)
{
        va_list ap;
        char *p;

        va_start(ap, fmt);
        for (p = fmt; *p; p++) {
                if (*p != '%') {
                        putchar(*p);
                        continue;
                }
                switch (*++p) {
                        case 'd':
                                type.d = va_arg(ap, int);
                                printf("%d", type);
                                break;
                        case 'l':
                                if (*++p == 'd') type.ld = va_arg(ap, int), printf("%ld", type);
                                break;
                        case 'u':
                                if (*++p == 'd') type.ud = va_arg(ap, int), printf("%u", type);
                                break;
                        case 'f':
                                type.f = va_arg(ap, double);
                                printf("%f", type);
                                break;
                        case 's':
                                for (type.s = va_arg(ap, char *); *type.s; type.s++)
                                        putchar(*type.s);
                                break;
                        default:
                                putchar(*p);
                                break;
                }
        }
}

int main(void)
{
        char *fmt = "%ld\n";
        unsigned int u = 10U;
        minprintf(fmt, u);
        return 0;
}
