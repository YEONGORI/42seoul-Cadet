/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:28:03 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/17 22:13:15 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_option(char *s)
{
	int	i;

	i = 0;
	if (s[0] != '-')
		return (0);
	while (s[++i])
	{
		if (s[i] != 'n')
			return (0);
	}
	return (1);
}

int	echo_option(char **argu)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (argu[++i])
	{
		if (is_option(argu[i]))
			ret++;
		else
			return (ret);
	}
	return (ret);
}

void	echo(char **argu)
{
	int	i;
	int	op;

	i = 1;
	op = 0;
	if (argu)
	{
		if (echo_option(argu))
		{
			op = echo_option(argu);
			i = op + 1;
		}
		while (argu[i])
		{
			ft_putstr_fd(argu[i], 1);
			if (argu[i + 1] != NULL)
				ft_putchar_fd(' ', 1);
			i++;
		}
		if (!op)
			ft_putchar_fd('\n', 1);
	}
	g_env.ret_exit = 0;
}
