/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:01:09 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/27 16:48:53 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

void	go_up(t_map *map)
{
	map -> fox_pos_y += 1;
	if (is_tree(map))
	{
		map -> fox_pos_y -= 1;
		return ;
	}
	if (is_hole(map))
		return ;
	if (is_coin(map))
		map -> score += 1;
	mlx_put_image_to_window(map -> mlx, map -> window, map -> grass,
		map -> fox_pos_x * 64, (map -> fox_pos_y - 1) * 64);
	mlx_put_image_to_window(map -> mlx, map -> window, map -> fox,
		map -> fox_pos_x * 64, map -> fox_pos_y * 64);
	map -> steps += 1;
	printf("UP\n");
	show_steps(map);
}

void	go_down(t_map *map)
{
	map -> fox_pos_y -= 1;
	if (is_tree(map))
	{
		map -> fox_pos_y += 1;
		return ;
	}
	if (is_hole(map))
		return ;
	if (is_coin(map))
		map -> score += 1;
	mlx_put_image_to_window(map -> mlx, map -> window, map -> grass,
		map -> fox_pos_x * 64, (map -> fox_pos_y + 1) * 64);
	mlx_put_image_to_window(map -> mlx, map -> window, map -> fox,
		map -> fox_pos_x * 64, map -> fox_pos_y * 64);
	map -> steps += 1;
	printf("DOWN\n");
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
	if (is_hole(map))
		return ;
	if (is_coin(map))
		map -> score += 1;
	mlx_put_image_to_window(map -> mlx, map -> window, map -> grass,
		(map -> fox_pos_x + 1) * 64, map -> fox_pos_y * 64);
	mlx_put_image_to_window(map -> mlx, map -> window, map -> fox,
		map -> fox_pos_x * 64, map -> fox_pos_y * 64);
	map -> steps += 1;
	printf("LEFT\n");
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
	if (is_hole(map))
		return ;
	if (is_coin(map))
		map -> score += 1;
	mlx_put_image_to_window(map -> mlx, map -> window, map -> grass,
		(map -> fox_pos_x - 1) * 64, map -> fox_pos_y * 64);
	mlx_put_image_to_window(map -> mlx, map -> window, map -> fox,
		map -> fox_pos_x * 64, map -> fox_pos_y * 64);
	map -> steps += 1;
	printf("RIGHT\n");
	show_steps(map);
}
