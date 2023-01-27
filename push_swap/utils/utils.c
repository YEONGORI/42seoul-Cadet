#include "../push_swap.h"

int	to_int(char *av)
{
	long long	i;
	long long	r;
	long long	m;

	i = -1;
	r = 0;
	m = 1;
	if (av[0] == '-')
	{
		m = -1;
		i++;
	}
	while (av[++i])
	{
		r *= 10;
		r += (av[i] - '0');
	}
	is_integer(r * m);
	return (r * m);
}

int to_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}