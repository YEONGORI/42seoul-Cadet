/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:03:33 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/27 15:22:19 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

int	is_tree(t_map *map)
{
	if (map -> map_data[map -> fox_pos_x][map -> fox_pos_y] == '1')
		return (1);
	return (0);
}

int	is_hole(t_map *map)
{
	if (map -> map_data[map -> fox_pos_x][map -> fox_pos_y] == 'E')
		return (1);
	return (0);
}

int	is_coin(t_map *map)
{
	if (map -> map_data[map -> fox_pos_x][map -> fox_pos_y] == 'C')
		return (1);
	return (0);
}

// int	is_exceed_left(t_map *map)
// {
// }

// int	is_exceed_right(t_map *map)
// {
// }