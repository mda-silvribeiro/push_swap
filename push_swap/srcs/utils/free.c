#include "library.h"

void free_stack(t_node *a)
{
    t_node *aux;

    while(a)
    {
        aux = a;
        a = a->next;
        if (aux)
            free(aux);
    }
    a = NULL;
}