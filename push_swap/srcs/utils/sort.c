#include "library.h"

int ft_isSorted(t_node *a)
{
	while(a->next)
	{
		if(a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

void	half(t_node **a, t_node **b, int size)
{
	int boo;
	int count;

	count = 0;
	while (count++ < 2)
	{
		boo = 0;
		if (position(min(*a), *a) < size / 2)
			boo = 1;
		while((*a)->data != min(*a))
		{
			if (boo)
				ra(a, 1);
			else
				rra(a, 1);
		}
		pb(a, b, 1);
	}
}

void short_sort(t_node **a, int i)
{
	t_node *b;
	
	b = 0;
	if(i > 3)
		half(a, &b, i);
	while(!ft_isSorted(*a))
	{
		if((*a)->data >= max(*a, 0))
			ra(a, 1);
		else if ((*a)->data > (*a)->next->data)
			ft_swapa(*a, 1);
		else
			ra(a, 1);
	}
	if(i > 3)
	{
		pa(a, &b, 1);
		pa(a, &b, 1);
	}
	i++;
}

void short_negative(t_node **a, int i)
{
	t_node *b;
	
	b = 0;
	if(i > 3)
		half(a, &b, i);
	while(!ft_isSorted(*a))
	{
		if ((*a)->data > (*a)->next->data)
			ft_swapa(*a, 1);
		else
			ra(a, 1);
	}
	if(i > 3)
	{
		pa(a, &b, 1);
		pa(a, &b, 1);
	}
}
