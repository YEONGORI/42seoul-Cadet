#include "../push_swap.h"

void rev_resolve_both(s_stack **a, s_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        (*cost_a)++;
        (*cost_b)++;
        reverse_both(a, b);
    }
}

void resolve_both(s_stack **a, s_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        (*cost_a)--;
        (*cost_b)--;
        printf("h\n");
        rotate_both(a, b);
        printf("j\n");
    }
}

void resolve_a(s_stack **a, int *cost_a)
{
    while (*cost_a != 0)
    {
        if (*cost_a > 0)
        {
            printf("- %d\n", *cost_a);
            rotate_a(a);
            (*cost_a)--;
        }
        else if (*cost_a < 0)
        {
            printf("- %d\n", *cost_a);
            reverse_a(a);
            (*cost_a)++;
        }
    }
}

void resolve_b(s_stack **b, int *cost_b)
{
    while (*cost_b != 0)
    {
        if (*cost_b > 0)
        {
            rotate_b(b);
            (*cost_b)--;
            printf("2\n");
        }
        else if (*cost_b < 0)
        {
            reverse_b(b);
            (*cost_b)++;
        }
    }
}