/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:53:13 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/10 11:51:37 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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
		else if (map[i] == 'C')
			carrot_cnt++;
		else if (map[i] == 'P')
			fox_cnt++;
		else if (map[i] != '1' && map[i] != '0' && map[i] != '\n'
			&& map[i] != 13)
			return (0);
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
	while (line_map[++i])
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

	j = -1;
	while (rect_map[++j])
	{
		i = 0;
		while (i < ft_strlen(rect_map[j]) && rect_map[j][i])
		{
			if (i == 0 || j == 0 || i == ft_strlen(rect_map[j]) - 1)
				if (rect_map[j][i] != '1')
					return (0);
			i++;
		}
	}
	return (1);
}

static int	is_clearable(char **rect_map)
{
	int		wid;
	int		hei;
	int		coin;
	t_pair	st;
	t_pair	en;

	hei = -1;
	coin = 0;
	while (rect_map[++hei])
	{
		wid = -1;
		while (rect_map[hei][++wid])
		{
			if (rect_map[hei][wid] == 'P')
				st = make_pair(hei, wid);
			if (rect_map[hei][wid] == 'E')
				en = make_pair(hei, wid);
			if (rect_map[hei][wid] == 'C')
				coin++;
		}
	}
	if (!clearable(rect_map, st, en, coin))
		return (0);
	return (1);
}

void	map_checker(char *line_map, char **rect_map)
{
	int	height;

	height = 0;
	while (rect_map[height])
		height++;
	if (!is_contains(line_map) || !is_retangular(rect_map) || \
		!is_surrounded(rect_map) || !is_clearable(rect_map))
	{
		write(2, "Map is wrong -> Error\n", 22);
		free((void *) line_map);
		free_char(rect_map, height);
		exit(EXIT_FAILURE);
	}
}
