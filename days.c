#include <stdio.h>

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

char *month_name(int n)
{
        static char *name[] = {
                "Illegal month", "January", "Fabruary", "March", "April", "May",
                "June", "July", "August", "September", "Octuber", "November", "December"
        };
        return ((n <= 0 || n > 12) ? name[0] : name[n]);
}

int day_of_year(int year, int month, int day)
{
        int i, leap;

        leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
        for (i = 1; i < month; i++)
                day += *(*(daytab + leap) + i);
        return (day);
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
        int i, leap;

        leap = year%4== 0 && year%100 != 0 || year%400 == 0;
        for (i = 0; yearday > daytab[leap][i]; i++)
                yearday -= *(*(daytab + leap) + i);
        *pmonth = i;
        *pday = yearday;
}

int main(void)
{
        int d = 9;
        int m = 11;
        int y = 2024;
        d = day_of_year(y, m, d);
        month_day(y, d, &m, &d);
        printf("%d/%d/%d\t%s\n", d, m, y, month_name(m));
        return (0);
}
