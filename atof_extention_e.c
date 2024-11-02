#include <stdio.h>

int _isspace(char c)
{
        return (c == ' ' || c == '\t' || c == '\n');
}

int _isdigit(char c)
{
        return (c >= '0' && c <= '9');
}

double _atof(char *s)
{
        int i, sign;
        double pow, val;

        for (i = 0; _isspace(s[i]); ++i)
                ;
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
                i++;
        for (val = 0.0; _isdigit(s[i]); ++i)
                val = val * 10.0 + (s[i] - '0');
        if (s[i] == '.')
                i++;
        for (pow = 1.0; _isdigit(s[i]); ++i) {
                val = val * 10.0 + (s[i] - '0');
                pow *= 10.0;
        }
        if (s[i] == 'e' || s[i] == 'E') {
                i++;
                int exp = (int) (_atof(&s[i]));
                while (exp < 0)
                        pow *= 10.0, exp++, printf("p: %f\n", pow);
                while (exp > 0)
                        pow /= 10.0, exp--, printf("p: %f\n", pow);
        }
        return (sign * val / pow);
}

int main(void)
{
        char *s = "   \t  123.45e-6";
        printf("%s\n", s);
        printf("%f\n", _atof(s));

        char *s2 = "   \t  123.45e6";
        printf("%s\n", s2);
        printf("%f\n", _atof(s2));

        char *s3 = "   \t  123.45E-6";
        printf("%s\n", s3);
        printf("%f\n", _atof(s3));

        char *s4 = "   \t  123.45e6";
        printf("%s\n", s4);
        printf("%f\n", _atof(s4));
        return (0);
}
