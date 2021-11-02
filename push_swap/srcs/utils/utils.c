#include "library.h"
#include "libft.h"

int check_args(char *av, int c)
{
	int len;
	while(av[c])
	{
		len = 0;
		if (((!ft_isdigit(av[c]) && (av[c] != '-' && av[c] != '+')) || 
		(av[c] == '-' && (!ft_isdigit(av[c + 1]))) || ((av[c] == '-' ||
		av[c] == '+') && (av[c + 1] == '+' || av[c + 1] == '-'))))
			return (0);
		while(ft_isdigit(av[c]))
		{
			len++;
			if (len == 10 && ((av[c] > '7' || ft_isdigit(av[c + 1])) &&	av[c - len] != '-'))
				return (0);
			if (len == 10 && ((av[c] > '8' || ft_isdigit(av[c + 1])) && av[c - len] != '-'))
				return (0);
			c++;
		}
		if (((av[c] == ' ' || ((av[c]) && ft_isdigit(av[c + 1])) || ((av[c] == '+') && ft_isdigit(av[c + 1]))) && av[c + 1]))
			c++;
	}
	return (1);
}

void config_list(t_node **a, int n)
{
	t_node *new;
	t_node *aux;

	aux = *a;
	new = malloc(sizeof(t_node));
	if (new)
	{
		new->data = n;
		new->next = NULL;
		if(*a)
		{
			while(aux->next)
				aux = aux->next;
			aux->next = new;
		}
		else
		{
			*a = new;
			return ;
		}
	}
}

t_node *create_list(t_node *a, char **av, int ac)
{
	int i;
	int j;

	i = 1;
	while(i < ac)
	{
		j = 0;
		while(av[i][j])
		{
			config_list(&a, ft_atoi(&av[i][j]));
			while(ft_isdigit(av[i][j]) || av[i][j] == '-' || av[i][j] == '+' || (av[i][j-1] == '-'))
				j++;
			if (av[i][j] == ' ')
				j++;
		}
		i++;
	}
	return (a);
}

/*t_node *create_list(t_node *a, char **av)
{
	t_node *head;
    t_node *tmp;
    t_node *last;
	int i;

	i = 1;
	a = malloc(sizeof(t_node));
	if (!a)
		exit_error(-2);
    a->data = ft_atoi(av[1]);
    a->next = 0;
    a->prev = a;
    head = a;
	printf("%d\n", a->data);
	while(av[++i])
	{
    	tmp = (t_node *)malloc(sizeof(t_node));
		tmp->data = ft_atoi(av[i]);
    	tmp->next = 0;
    	a->next = tmp;
    	last = a;
    	a = a->next;
    	a->prev = last;
		printf("%d\n", a->data);
    }
    a = head;
	return (a);
}*/

int	check_dup(t_node *a)
{
	int aux;
	t_node *tmp;

	aux = a->data;
	tmp = a;
	while(a->next)
	{
		a = a->next;
		if(a->data == aux)
			return (1);
	}
	if (tmp->next)
		if(check_dup(tmp->next))
			return (1);
	return(0);

}

t_node *ft_create(char **av, int ac)
{

	t_node *a;
    int i;
	i = 0;

	a = NULL;
	ac++;
	while(av[++i])
	{
		if (!(check_args(av[i], 0)) || !av[1][0])
			return (0);
	}
   	a = create_list(a, av, i);
	if (check_dup(a))
	{
		free_stack(a);
		return (NULL);
	}
    return(a);  
}