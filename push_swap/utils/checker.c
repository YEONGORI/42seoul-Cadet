#include "../push_swap.h"

void	is_parameter_specified(char **av)
{
	if (av == NULL || *av == NULL)
		exit(0);
}

void	is_parameter_unique(char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (av[++i])
	{
		tmp = ft_strdup(av[i]);
		j = i + 1;
		while (av[j])
		{
			if (!ft_strcmp(tmp, av[j]))
			{
				free(tmp);
				tmp = NULL;
				write(1, "Error: some arguments are duplicated\n", 38);
				exit(1);
			}
			j++;
		}
		free(tmp);
	}
}

void	is_number(char *str)
{
	int	i;

	i = -1;
	if (!str)
	{
		write(1, "Error: some arguments aren't number\n", 37);
		exit(1);
	}
	while (str[++i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
		{
			write(1, "Error: some arguments aren't number\n", 37);
			exit(1);
		}
	}
}

void	is_integer(long long n)
{
	if (n > 2147483647 || n < -2147483648)
	{
		write(1, "Error: some arguments aren't integers\n", 39);
		exit(1);
	}
}

int	is_sorted(s_stack **a)
{
	s_stack	*tmp;
	int		cur;

	tmp = *a;
	cur = tmp->data;
	while (tmp -> next)
	{
		tmp = tmp -> next;
		if (cur > tmp->data)
			return (0);
	}
	return (1);
}