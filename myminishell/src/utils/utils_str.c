/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:52:47 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 18:00:11 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strhei(char **square)
{
	int	hei;

	hei = 0;
	while (square[hei])
		hei++;
	return (hei);
}

void	free_square(char *square)
{
	int	i;

	i = 0;
	if (square)
	{
		while (square[i])
			free(square[i++]);
		free(square);
	}
}
