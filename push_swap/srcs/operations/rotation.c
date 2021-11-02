#include "library.h"

void    ra(t_node **a, int cmd)
{
    t_node *new_last;
    t_node *new_head;

    if (!(*a) || !(*a)->next)
        return ;
    new_last = *a;
    new_head = (*a)->next;
    while((*a)->next)
        *a = (*a)->next;
    (*a)->next = new_last;
    *a = new_head;
    new_last->next = NULL;
    if (cmd == 1)
        write(1, "ra\n", 3);
}

void    rb(t_node **b, int cmd)
{
    t_node *new_last;
    t_node *new_head;

    if(!(*b) || !(*b)->next)
        return ;
    new_last = *b;
    new_head = (*b)->next;
    while((*b)->next)
        *b = (*b)->next;
    (*b)->next = new_last;
    *b = new_head;
    if (cmd == 1)
        write(1, "rb\n", 3);
}

void rr(t_node **a, t_node **b, int cmd)
{
    ra(a, 0);
    rb(b, 0);
    if (cmd == 1)
        write(1, "rr\n", 3);
}