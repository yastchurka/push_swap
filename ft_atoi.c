int ft_atoi(char argv[])
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (argv[i] != '\0')
	{
		nb = nb * 10 + (argv[i] - '0');
		i++;
	}
	return (nb);
}