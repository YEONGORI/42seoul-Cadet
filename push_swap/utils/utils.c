#include "../push_swap.h"

int to_int(char *av)
{
    long long i;
    long long r;
    long long m;

    i = -1;
    r = 0;
    m = 1;
    if (av[0] == '-')
    {
        m = -1;
        i++;
    }
    while (av[++i])
    {
        r *= 10;
        r += (av[i] - '0');
    }
    is_integer(r * m);
    return (r * m);
}

int to_abs(int n)
{
    if (n == -2147483648)
        return (2147483647);
    if (n < 0)
        return (n * -1);
    return (n);
}

s_stack *get_bottom(s_stack *s)
{
    while (s && s->next)
        s = s->next;
    return (s);
}

s_stack *get_before_bottom(s_stack *s)
{
    while (s && s->next && s->next->next)
        s = s->next;
    return (s);
}