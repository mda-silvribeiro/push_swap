#include "libft.h"

int ft_isdigit(char **a)
{
    if (**a >= '0' && **a <= '9')
        return (1);
    return (0);
}