/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:58:45 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/03 15:45:41 by yeongele         ###   ########.fr       */
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

void	set_map(t_map *map)
{
	int	x;
	int	y;
	int	width;
	int	height;

	y = -1;
	width = ft_strlen(map -> map_data[0]);
	height = 0;
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
		}
	}
	map -> width = width;
	map -> height = height;
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
	rect_map = ft_split(line_map, '\n');
	if (!map_checker(line_map, rect_map))
		exit(0);
	close(fd);
	free((void *)line_map);
	return (rect_map);
}
