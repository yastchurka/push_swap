#include "push_swap.h"

long	small_atoi(char *str)
{
	int				neg;
	unsigned long	num;
	int				i;

	i = 0;
	neg = 1;
	num = 0;
 	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}