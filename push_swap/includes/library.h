#ifndef LIBRARY_H
# define LIBRARY_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_node
{
    int value;
    int data;
    struct s_node *prev;
    struct s_node *next;
}              t_node;

typedef struct s_aux
{
    int a;
    int b;
    int max_a;
    int max_b;
    int pos_a;
    int pos_b;
}           t_aux;

void exit_error(int n);
//struct s_node *ft_setup(char **av, t_node *first, t_node *last, t_node *a);
//struct s_node *init_linked_list(char **av);


int     check_args(char *av, int c);
void config_list(t_node **a, int n);
t_node  *create_list(t_node *a, char **av, int ac);
int	    check_dup(t_node *a);
t_node  *ft_create(char **av, int ac);
void    ft_swapa(t_node *a, int cmd);
void    ft_swapb(t_node *b, int cmd);
void    ft_swapss(t_node *a, t_node *b, int cmd);
void    delete(t_node *node);
void    ft_pushb(t_node *from, t_node *to);
void	pa(t_node **a, t_node **b, int cmd);
void	pb(t_node **a, t_node **b, int cmd);
void    ra(t_node **a, int cmd);
void    rb(t_node **b, int cmd);
void    rr(t_node **a, t_node **b, int cmd);
void    rra(t_node **a, int cmd);
void    rrb(t_node **b, int cmd);
void    rrr(t_node **a, t_node **b, int cmd);
int size_struct(t_node *a);
int ft_isSorted(t_node *a);
int max(t_node *a, int op);
int min(t_node *a);
int position(int pos, t_node *a);

int iSsort(int *m);
void sort_matriz(int *m, int size);
int median(t_node *a, int size);
void aux_max(t_node **a, t_node **b, int max, t_aux *data);
void config_a(t_node **a, t_node **b, t_node *aux, t_aux *data);
void config_rot(int tmp_size, t_node **a, t_node **b, t_node **aux, int m);
int big_sort(t_node **a, int size);

void	half(t_node **a, t_node **b, int size);
void    short_sort(t_node **a, int i);
void short_negative(t_node **a, int i);
int     resolve(t_node **a, int ac);
int     main(int ac, char **av);
void free_stack(t_node *a);

#endif