/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:03:33 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/08 13:03:13 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

int	is_tree(t_map *map)
{
	if (map -> map_data[map -> fox_pos_y][map -> fox_pos_x] == '1')
		return (1);
	return (0);
}

void	is_hole(t_map *map)
{
	if (map -> map_data[map -> fox_pos_y][map -> fox_pos_x] == 'E')
	{
		free_struct(map);
		exit(EXIT_SUCCESS);
	}
}

int	is_coin(t_map *map)
{
	if (map -> map_data[map -> fox_pos_y][map -> fox_pos_x] == 'C')
		return (1);
	return (0);
}
