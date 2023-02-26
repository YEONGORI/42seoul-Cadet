/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:58:45 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/26 21:26:10 by yeongele         ###   ########.fr       */
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

char	**download_map(char *file)
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
		line_map = ft_strjoin(line, line_map);
	}
	rect_map = ft_split(line_map, '\n');
	if (!map_checker(line_map, rect_map))
		exit(0);
	close(fd);
	free(line_map);
	return (rect_map);
}