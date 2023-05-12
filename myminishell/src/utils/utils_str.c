/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:52:47 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/12 12:13:33 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
