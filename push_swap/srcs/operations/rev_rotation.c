#include "library.h"

void rra(t_node **a, int cmd)
{
    t_node *new_top;
    t_node *head;
    
    if (!(*a) || !(*a)->next)
        return ;
    head = *a;
    while((*a)->next)
        *a = (*a)->next;
    new_top = (*a);
    (*a)->prev->next = NULL;
    *a = head->prev;
    (*a) = new_top;
    (*a)->next = head;
    if (cmd == 1)
        write(1, "rra\n", 4);
}

void rrb(t_node **b, int cmd)
{
    t_node *new_top;
    t_node *head;

    if (!(*b) || !(*b)->next)
        return ;
    head = *b;
    while((*b)->next)
        *b = (*b)->next;
    new_top = *b;
    (*b)->prev->next = NULL;
    *b = head;
    (*b)->prev = new_top;
    (*b)->prev->next = head;
    if (cmd == 1)
        write(1, "rrb\n", 4);
}

void rrr(t_node **a, t_node **b, int cmd)
{
    rra(a, 0);
    rrb(b, 0);
    if (cmd == 1)
        write(1, "rrr\n", 4);
}