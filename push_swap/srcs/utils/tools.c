#include "library.h"

int max(t_node *a, int op)
{
    int max;

    max = a->data;
    while(a->next)
    {
        if (a->data > max && a->data != op)
            max = a->data;
        a = a->next;
    }
    if(a->data > max && a->data != op)
        max = a->data;
    return (max);
}

int min(t_node *a)
{
    int min;

    min = a->data;
    while(a->next)
    {
        if(a->data < min)
            min = a->data;
        a = a->next;
    }
    if (a->data < min)
        min = a->data;
    return (min);
}

int position(int pos, t_node *a)
{
    int i;

    i = 0;
    while(a->data != pos)
    {
        i++;
        a = a->next;
    }
    return (i);
}