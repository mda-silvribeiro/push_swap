#include "library.h"

int isSort(int *m)
{
    int i;

    i = 0;
    while(m[i + 1])
    {
        if(m[i] > m[i+1])
            return (0);
        i++;
    }
    return (1);
}

void sort_matriz(int *m, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = 0;
    while(i < size - 1)
    {
        j = 0;
        while(j < size - i -1)
        {
            if (m[j] > m[j + 1])
            {
                tmp = m[j];
                m[j] = m[j+1];
                m[j+1] = tmp;
                j++;
            }
            i++;
        }
    }
}

int median(t_node *a, int size)
{
    int aux;
    int *median;

    aux = 0;
    median = (int *)malloc(sizeof(int));
    while(a->next)
    {
        median[aux] = a->data;
        a = a->next;
        aux++;
    }
    sort_matriz(median, size);
    aux = 0;
    while(aux < size / 2)
        ++aux;
    aux = median[aux];
    free(median);
    return (aux);
}

void aux_max(t_node **a, t_node **b, int max, t_aux *data)
{
    int boo;

    boo = 0;
    if((*b)->data < max)
    {
        while((*b)->data != max)
        {
            if ((*b)->next->data == max)
            {
                ft_swapb(*b, 1);
                pa(a, b, 1);
                boo = 1;
                break ;
            }
            if (data->a == 1)
                rb(b, 1);
            else
                rrb(b, 1);
        }
    }
    if (!boo)
        pa(a, b, 1);
}

void config_a(t_node **a, t_node **b, t_node *aux, t_aux *data)
{
    while(aux->value)
    {
        data->a = 0;
        data->b = 0;
        data->max_b = max(*b, -2147483648);
        data->max_a = max(*b, data->max_b);
        if ((data->pos_a = position(data->max_b, *b)) < aux->value / 2)
            data->a = 1;
        if (data->max_a != -214783648 && (data->pos_b = position(data->max_a, *b)) < aux->value / 2)
            data->b = 1;
        if (data->max_a != -214783648 && data->a == data->b && ((data->pos_a > data->pos_b && data->a) ||
            (data->pos_a < data->pos_b && !data->a)))
        {
            aux_max(a, b, data->max_a, data);
            aux_max(a, b, data->max_b, data);
            ft_swapa(*a, 1);
            aux->value--;
        }
        else
            aux_max(a, b, data->max_b, data);
        aux->value--;
    }
}

void config_rot(int tmp_size, t_node **a, t_node **b, t_node **aux, int m)
{
    while (tmp_size && (*aux)->data > 2)
    {
        if((*a)->data <= m)
        {
            pb(a, b, 1);
            if((*b)->data < median(*b, (*aux)->value) && (*aux)->value > 1)
            {
                if ((*a)->data > m)
                    rr(a, b, 1);
                else
                    rb(b, 1);
            }
            (*aux)->data--;
            (*aux)->value++;
        }
        else
            ra(a, 1);
        tmp_size--;
    }
}

int big_sort(t_node **a, int size)
{
    int m;
    int tmp;
    t_node *b;
    t_node *aux;
    t_aux *data;

    b = 0;
    data = malloc(sizeof(t_aux));
    aux = malloc(sizeof(t_node));
    aux->data = size;
    aux->value = 0;
    while(aux->data > 2)
    {
        m = median(*a, aux->data);
        tmp = aux->data;
        config_rot(tmp, a, &b, &aux, m);
    }
    pb(a, &b, 1);
    pb(a, &b, 1);
    aux->value += 2;
    config_a(a, &b, aux, data);
    free(aux);
    free(data);
    return (1);
}