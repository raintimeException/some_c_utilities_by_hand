#include <stdio.h>

#define dprint(e)       printf(#e " = %d\n", e)
#define sprint(e)       printf(#e " = %s\n", e)

typedef struct s_person {
        int age;
        char *name;
} s_person;


int main(void)
{
        s_person *ps_person;
        dprint(ps_person->age = 20);
        sprint(ps_person->name = "Ivan");
        return 0;
}
