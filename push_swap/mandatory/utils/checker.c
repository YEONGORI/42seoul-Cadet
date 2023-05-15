/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:10:34 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 12:18:02 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		free(tmp);
	}
}

void	is_number(char *str, t_stack **a)
{
	int	i;

	i = -1;
	if (!str || !*str)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (str[++i])
	{
		if (str[i] == '-')
		{
			if (i != 0 || str[i + 1] == '-')
				exit_error(a, NULL);
			if (i == 0 && str[1] == '\0')
				exit_error(a, NULL);
		}
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			exit_error(a, NULL);
	}
}

void	is_integer(long long n, t_stack **s)
{
	if (n > C_INT_MAX || n < C_INT_MIN)
		exit_error(s, NULL);
}

int	is_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp -> next)
	{
		if (tmp -> data > tmp -> next -> data)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}
