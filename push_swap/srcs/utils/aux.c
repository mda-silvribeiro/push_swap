#include "library.h"

int	ft_atoi(const char *str)
{
	int pos;
	int result;

	result = 0;
	pos = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	if (*str == 45 || *str == 43)
		if (*(str++) == 45)
			pos *= -1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result *= 10;
			result += (*(str++) - '0');
		}
		else
			return (result * pos);
	}
	return (result * pos);
}

int ft_isdigit(int a)
{
    if (a >= 48 && a <= 57)
        return (1);
    return (0);
}