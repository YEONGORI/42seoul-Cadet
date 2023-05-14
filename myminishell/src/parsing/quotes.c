/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:22:06 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 16:27:38 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_quote_len(char *input, int flag)
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
		if (input[i] == NULL)
			break ;
	}
	return (len);
}

int	get_end_quote(char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
		if (s[i] == c)
			return (i);
	if (c == NULL)
		return (i);
	return (-1);
}

int	quotes(char *s)
{
	int		i;
	int		flag;
	char	type;

	i = -1;
	flag = 0;
	if (!s)
		return (0);
	while (s[++i])
	{
		if ((s[i] == '\'' || s[i] == '\"') && flag == 0)
		{
			type = s[i];
			flag = 1;
		}
		else if (flag && s[i] == type)
			flag = 0;
	}
	if (flag)
		write(1, "plz close quotes.\n", 18);
	return (flag);
}

int	empty(char *s)
{
	int		i;
	char	c;

	i = -1;
	if (s[0] && s[1] && (s[i] == '\'' || s[i] == '\"'))
	{
		c = s[0];
		while (s[++i])
		{
			if (c != s[i])
				break ;
			if (!s[i])
			{
				ft_putstr_fd("bash: command not found: \n", 2);
				g_env.ret_exit = 127;
				return (1);
			}
		}
	}
}
