#define ALLOCSIZE       4096
static char allocbuff[ALLOCSIZE];

static char *allocp = allocbuff;

char *_alloca(int n)
{
        if (allocbuff + ALLOCSIZE - allocp >= n)
        {
                allocp += n;
                return (allocp - n);
        } else {
                return (0);
        }
}

void _afree(char *p)
{
        if (p > allocbuff && p < allocbuff + ALLOCSIZE)
                allocp = p;
}
