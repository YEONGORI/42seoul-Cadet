/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:58:45 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/09 10:31:20 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_ber(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '.')
		i++;
	if (file[++i] != 'b')
		return (0);
	if (file[++i] != 'e')
		return (0);
	if (file[++i] != 'r')
		return (0);
	return (1);
}

static int	is_opened(int fd)
{
	if (fd < 0)
		return (0);
	return (1);
}

void	set_map(t_map *map, int width, int height, int coin)
{
	int	x;
	int	y;

	y = -1;
	width = ft_strlen(map -> map_data[0]);
	map -> coin_cnt = 0;
	while (map -> map_data[height])
		height++;
	while (map -> map_data[++y])
	{
		x = -1;
		while (map -> map_data[y][++x])
		{
			if (map -> map_data[y][x] == 'P')
			{
				map -> fox_pos_x = x;
				map -> fox_pos_y = y;
			}
			if (map -> map_data[y][x] == 'C')
				coin++;
		}
	}
	map -> width = width;
	map -> height = height;
	map -> coin_cnt = coin;
}

char	**get_map(char *file)
{
	int		fd;
	char	*line;
	char	*line_map;
	char	**rect_map;

	fd = open(file, O_RDONLY);
	line = "";
	line_map = ft_strdup("");
	if (!is_ber(file) || !is_opened(fd))
		exit(0);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_map = ft_strjoin(line_map, line);
		free((void *)line);
	}
	close(fd);
	rect_map = ft_split(line_map, '\n');
	map_checker(line_map, rect_map);
	free((void *)line_map);
	return (rect_map);
}
