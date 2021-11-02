#include "library.h"

int resolve(t_node **a, int ac)
{
	if (ac < 4 && (*a)->data < 0)
		short_negative(a, ac);
	else if (ac <= 8)
		short_sort(a, ac);
	else
	{
		if(!big_sort(a, ac))
			return (0);
	}
	return (1);
}
int size_struct(t_node *a)
{
	int i;

	i = 0;
	while(a != 0)
	{
		i++;
		a = a->next;
	}
	return (i);
}
int main(int ac, char **av)
{
	t_node *a;
    if(ac <= 1)
        return (0);
	if (!(a = ft_create(av, ac)))
		exit_error(-3);
	if(ft_isSorted(a))
		return (0);
	if(!(resolve(&a,size_struct(a))))
		exit_error(-3);
	while(a != 0)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
	free_stack(a);
	return (0);
}
