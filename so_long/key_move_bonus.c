/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:01:09 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/16 12:36:46 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

static void	show_steps(t_map *map)
{
	char	*s;

	mlx_put_image_to_window(map -> mlx, map -> window, map -> tree, 0, 0);
	s = ft_itoa(map -> steps);
	mlx_string_put(map->mlx, map->window, 32, 32, 0x000000ff,
		s);
	free(s);
}

void	go_down(t_map *map)
{
	map -> fox_pos_y += 1;
	if (is_tree(map))
	{
		map -> fox_pos_y -= 1;
		return ;
	}
	if (is_coin(map))
		map -> score += 1;
	mlx_put_image_to_window(map -> mlx, map -> window, map -> grass,
		map -> fox_pos_x * 64, (map -> fox_pos_y - 1) * 64);
	mlx_put_image_to_window(map -> mlx, map -> window, map -> fox,
		map -> fox_pos_x * 64, map -> fox_pos_y * 64);
	is_hole(map);
	map -> steps += 1;
	show_steps(map);
}

void	go_up(t_map *map)
{
	map -> fox_pos_y -= 1;
	if (is_tree(map))
	{
		map -> fox_pos_y += 1;
		return ;
	}
	if (is_coin(map))
		map -> score += 1;
	mlx_put_image_to_window(map -> mlx, map -> window, map -> grass,
		map -> fox_pos_x * 64, (map -> fox_pos_y + 1) * 64);
	mlx_put_image_to_window(map -> mlx, map -> window, map -> fox,
		map -> fox_pos_x * 64, map -> fox_pos_y * 64);
	is_hole(map);
	map -> steps += 1;
	show_steps(map);
}

void	go_left(t_map *map)
{
	map -> fox_pos_x -= 1;
	if (is_tree(map))
	{
		map -> fox_pos_x += 1;
		return ;
	}
	if (is_coin(map))
		map -> score += 1;
	mlx_put_image_to_window(map -> mlx, map -> window, map -> grass,
		(map -> fox_pos_x + 1) * 64, map -> fox_pos_y * 64);
	mlx_put_image_to_window(map -> mlx, map -> window, map -> fox,
		map -> fox_pos_x * 64, map -> fox_pos_y * 64);
	is_hole(map);
	map -> steps += 1;
	show_steps(map);
}

void	go_right(t_map *map)
{
	map -> fox_pos_x += 1;
	if (is_tree(map))
	{
		map -> fox_pos_x -= 1;
		return ;
	}
	if (is_coin(map))
		map -> score += 1;
	mlx_put_image_to_window(map -> mlx, map -> window, map -> grass,
		(map -> fox_pos_x - 1) * 64, map -> fox_pos_y * 64);
	mlx_put_image_to_window(map -> mlx, map -> window, map -> fox,
		map -> fox_pos_x * 64, map -> fox_pos_y * 64);
	is_hole(map);
	map -> steps += 1;
	show_steps(map);
}
