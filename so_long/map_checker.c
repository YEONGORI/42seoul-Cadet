/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:53:13 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/27 13:03:08 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_contains(char *map)
{
	int	i;
	int	hole_cnt;
	int	carrot_cnt;
	int	fox_cnt;

	i = -1;
	hole_cnt = 0;
	carrot_cnt = 0;
	fox_cnt = 0;
	while (map[++i] != 0)
	{
		if (map[i] == 'E')
			hole_cnt++;
		if (map[i] == 'C')
			carrot_cnt++;
		if (map[i] == 'P')
			fox_cnt++;
	}
	if (hole_cnt != 1 || carrot_cnt == 0 || fox_cnt != 1)
		return (0);
	return (1);
}

static int	is_retangular(char **line_map)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen(line_map[0]);
	while (!line_map[++i])
	{
		if (ft_strlen(line_map[i]) != width)
			return (0);
	}
	return (1);
}

static int	is_surrounded(char **rect_map)
{
	int	i;
	int	j;

	i = -1;
	while (rect_map[++i])
	{
		j = -1;
		while (++j < ft_strlen(rect_map[i]) && rect_map[i][j])
		{
			if (i == 0 || j == 0 || j == ft_strlen(rect_map[i]) - 1)
				if (rect_map[i][j] != '1')
					return (0);
		}
	}
	return (1);
}

int	map_checker(char *line_map, char **rect_map)
{
	if (!is_contains(line_map) || !is_retangular(rect_map) || \
		!is_surrounded(rect_map))
	{
		write(2, "Map is wrong -> Error\n", 22);
		return (0);
	}
	return (1);
}
