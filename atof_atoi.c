#include <stdio.h>

int main(void)
{
        double _atof(char *s);
        int _atoi(char *i), _isspace(char c), _isdigit(char c);
        char *s = "\t   -987.654";
        printf("%s\n", s);
        printf("%g\n", _atof(s));
        printf("%d\n", _atoi(s));
        return (0);
}

int _isspace(char c)
{
        return (c == ' ' || c == '\t' || c == '\n' ||\
                        c == '\f' || c == '\v' || c == '\r');
}

int _isdigit(char c)
{
        return (c >= '0' && c <= '9');
}

int _atoi(char *s)
{
        double _atof(char *s);
        return ((int) _atof(s));
}

double _atof(char *s)
{
        int i, sign;
        double val, power;

        for (i = 0; _isspace(s[i]); ++i)
                ;
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
                i++;
        for (val = 0; _isdigit(s[i]); ++i)
                val = val * 10.0 + (s[i] - '0');
        if (s[i] == '.')
                i++;
        for (power = 1; _isdigit(s[i]); ++i) {
                val = val * 10.0 + (s[i] - '0');
                power *= 10.0;
        }
        return (sign * val / power);
}
