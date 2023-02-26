/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:09:03 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/26 22:38:55 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_img(t_map *map)
{
	int	xy[2];

	map->fox = mlx_xpm_file_to_image(map->mlx, "./textures/fox.xpm",
			&xy[0], &xy[1]);
	map->carrot = mlx_xpm_file_to_image(map->mlx, "./textures/carrot.xpm",
			&xy[0], &xy[1]);
	map->tree = mlx_xpm_file_to_image(map->mlx, "./textures/tree.xpm",
			&xy[0], &xy[1]);
	map->hole = mlx_xpm_file_to_image(map->mlx, "./textures/hole.xpm",
			&xy[0], &xy[1]);
	map->forest = mlx_xpm_file_to_image(map->mlx, "./textures/forest.xpm",
			&xy[0], &xy[1]);
}

static void	parse_img(t_map *map, )
{

}

void	parse_map(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	create_img(map)''
}