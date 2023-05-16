/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:28:16 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 13:32:36 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_line(char *str)
{
	int		i;
	char	**split;

	i = 0;
	while (g_myenv.env[i])
	{
		split = ft_split(g_myenv.env[i], '=');
		if (ft_strcmp(split[0], str) == 0)
		{
			free_square(split);
			return (i);
		}
		free_square(split);
		i++;
	}
	return (-1);
}
