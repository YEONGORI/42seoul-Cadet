/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:09:03 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/27 13:12:27 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

static void	create_img(t_map *map)
{
	map->fox = mlx_xpm_file_to_image(map->mlx, "./textures/fox.xpm",
			&(map -> width), &(map -> height));
	map->carrot = mlx_xpm_file_to_image(map->mlx, "./textures/carrot.xpm",
			&(map -> width), &(map -> height));
	map->tree = mlx_xpm_file_to_image(map->mlx, "./textures/tree.xpm",
			&(map -> width), &(map -> height));
	map->hole = mlx_xpm_file_to_image(map->mlx, "./textures/hole.xpm",
			&(map -> width), &(map -> height));
	map->grass = mlx_xpm_file_to_image(map->mlx, "./textures/grass.xpm",
			&(map -> width), &(map -> height));
}

static void	parse_img(t_map *map, char c, int x, int y)
{
	if (c == 'P')
		mlx_put_image_to_window(map -> mlx, map -> window,
			map -> fox, x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(map -> mlx, map -> window,
			map -> carrot, x * 64, y * 64);
	else if (c == '1')
		mlx_put_image_to_window(map -> mlx, map -> window,
			map -> tree, x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(map -> mlx, map -> window,
			map -> hole, x * 64, y * 64);
	else if (c == '0')
		mlx_put_image_to_window(map -> mlx, map -> window,
			map -> grass, x * 64, y * 64);
}

void	parse_map(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	create_img(map);
	while (map -> map_data[++x])
	{
		y = -1;
		while (map -> map_data[x][++y] && map -> map_data[x][y] != '\n')
			parse_img(map, map -> map_data[x][y], x, y);
	}
}
