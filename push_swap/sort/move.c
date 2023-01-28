#include "../push_swap.h"

void get_cost(s_stack **a, s_stack **b)
{
    s_stack *b_tmp;
    int size_a;
    int size_b;

    b_tmp = *b;
    size_a = get_size(a);
    size_b = get_size(b);
    printf("size: %d   %d\n", size_a, size_b);
    while (b_tmp)
    {
        b_tmp->cost_b = b_tmp->cur_pos;
        if (b_tmp->cur_pos > size_b / 2)
            b_tmp->cost_b = (size_b - b_tmp->cur_pos) * -1;
        b_tmp->cost_a = b_tmp->target_pos;
        if (b_tmp->target_pos > size_a / 2)
            b_tmp->cost_a = (size_a - b_tmp->target_pos) * -1;
        printf("btmp: %d     %d\n", b_tmp->cost_a, b_tmp->cost_b);
        b_tmp = b_tmp->next;
    }
}

void move_start(s_stack **a, s_stack **b, int cost_a, int cost_b)
{
    printf("HIHIHIH\n");
    if (cost_a < 0 && cost_b < 0)
    {
        printf("QQQQ\n");
        rev_resolve_both(a, b, &cost_a, &cost_b);
    }
    else if (cost_a > 0 && cost_b > 0)
    {
        printf("WWWW\n");
        resolve_both(a, b, &cost_a, &cost_b);
    }
    printf("EEEE\n");
    resolve_a(a, &cost_a);
    resolve_b(b, &cost_b);
    push_a(a, b);
}

void move_cheapest(s_stack **a, s_stack **b)
{
    s_stack *tmp;
    int cheapest;
    int cost_a;
    int cost_b;

    tmp = *b;
    cheapest = 2147483647;
    while (tmp)
    {
        if (to_abs(tmp->cost_a) + to_abs(tmp->cost_b) < to_abs(cheapest))
        {
            cheapest = to_abs(tmp->cost_b) + to_abs(tmp->cost_a);
            printf("tmp cost a: %d\n", tmp->cost_a);
            printf("tmp cost b: %d\n", tmp->cost_b);
            cost_a = tmp->cost_a;
            cost_b = tmp->cost_b;
        }
        tmp = tmp->next;
    }
    printf("a: %d || b: %d\n", cost_a, cost_b);
    while (1)
        ;
    move_start(a, b, cost_a, cost_b);
}
