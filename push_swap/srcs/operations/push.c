#include "library.h"

void	pa(t_node **a, t_node **b, int cmd)
{
	t_node	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
    if (cmd == 1)
		write(1, "pa\n", 3);

}

void	pb(t_node **a, t_node **b, int cmd)
{
	t_node	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
    *a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
    if (cmd == 1)
		write(1, "pb\n", 3);
}