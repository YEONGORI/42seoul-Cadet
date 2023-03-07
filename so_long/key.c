/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:33:34 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/07 13:42:37 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

static void	leaks(void)
{
	system("leaks so_long");
}


int	end_game(t_map *map)
{
	printf("ESC\n\n");
	mlx_destroy_window(map -> mlx, map -> window);
	free_struct(map);
	atexit(leaks);
	exit(1);
	return (1);
}

int	key_down(int key_code, t_map *map)
{
	if (key_code == 'W' || key_code == KEY_W)
		go_up(map);
	else if (key_code == 'A' || key_code == KEY_A)
		go_left(map);
	else if (key_code == 'S' || key_code == KEY_S)
		go_down(map);
	else if (key_code == 'D' || key_code == KEY_D)
		go_right(map);
	else if (key_code == KEY_ESC)
		end_game(map);
	return (0);
}

void	apply_key(t_map *map)
{
	mlx_hook(map -> window, 2, 0, key_down, map);
	mlx_hook(map -> window, 17, 0, end_game, map);
	// mlx_loop(map -> mlx);
}
