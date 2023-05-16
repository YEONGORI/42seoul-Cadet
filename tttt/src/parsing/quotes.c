/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:22:06 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 22:35:21 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_only_quotation_len(char *input, int flag)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			if (flag == 0)
				flag = 1;
			else if (flag == 1)
				if (help_quote1(input, &i, &len))
					break ;
		}
		else
			len++;
		if (!input[i])
			break ;
	}
	return (len);
}

int	get_quotation_len(char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
		if (s[i] == c)
			return (i);
	if (!c)
		return (i);
	return (-1);
}

int	ch_quotes(char *input)
{
	int		i;
	int		flag;
	char	type;

	i = -1;
	flag = 0;
	if (!input)
		return (0);
	while (input[++i])
	{
		if ((input[i] == '\'' || input[i] == '\"') && flag == 0)
		{
			type = input[i];
			flag = 1;
		}
		else if (flag && input[i] == type)
			flag = 0;
	}
	if (flag)
		ft_putstr_fd("Unclosed quotes, please try again without it\n", 2);
	return (flag);
}

int	ch_empty(char *input)
{
	int		i;
	char	c;

	i = 0;
	if (input[0] && input[1] && (input[0] == '\'' || input[0] == '\"'))
	{
		c = input[0];
		while (input[++i])
		{
			if (c != input[i])
				break ;
			i++;
			if (!input[i])
			{
				ft_putstr_fd("bash: command not found: \n", 2);
				g_env.ret_exit = 127;
				return (1);
			}
		}
	}
	return (0);
}
