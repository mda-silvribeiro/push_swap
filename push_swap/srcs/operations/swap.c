#include "library.h"

void ft_swapa(t_node *a, int cmd)
{
    if(!a)
        return ;
    if(a->next)
    {
        a->next->value = a->data;
        a->data = a->next->data;
        a->next->data = a->next->value;
    }
    if (cmd == 1)
        write(1, "sa\n", 3);
}

void ft_swapb(t_node *b, int cmd)
{
     if(!b)
        return ;
    if(b->next)
    {
        b->next->value = b->data;
        b->data = b->next->data;
        b->next->data = b->next->value;
    }
    if (cmd == 1)
        write(1, "sb\n", 3);
}
void ft_swapss(t_node *a, t_node *b, int cmd)
{
    ft_swapa(a, cmd);
    ft_swapb(b, cmd);
    if (cmd == 1)
        write(1, "ss\n", 3);
}