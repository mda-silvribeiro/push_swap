#include "library.h"

void exit_error(int n)
{
    if (n == -1)
    	write(1, "Error: insuficient arguments", 28);
	if (n == -2)
		write(1, "Error: insuficient Dynamic Memory", 22);
    if (n == -3)
		write(1, "Error\n", 6);
	exit(0);
}