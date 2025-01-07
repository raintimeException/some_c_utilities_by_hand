#include <stdio.h>

#define SUPER_LOG(flag, ...) \
    if (flag) printf("%s: %d " __VA_ARGS__ "\n", __FILE__, __LINE__)

#define m_dprintf(e)  printf(#e" = %d\n", e)
#define m_fprintf(f)  printf(#f" = %f\n", f)

#define DEBUG_IS_ENABLED 1

#define m_MIN(a, b)     (((a) < (b)) ? (a) : (b))
#define m_MAX(a, b)     (((a) > (b)) ? (a) : (b))
#define m_PASTE(x, y)   x##y

int main(void)
{
    int a = 0;
    int b = 1;

    printf("%d\n", m_MIN(a, b));
    printf("%d\n", m_MAX(a, b));

    m_dprintf(1 + 2);
    m_fprintf(1.0 + 2.0);
    m_fprintf(1 + 2);

    int m_PASTE(a, b) = 20;
    m_dprintf(m_PASTE(a, b));
    return 0;
}
