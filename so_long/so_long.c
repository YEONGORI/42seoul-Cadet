/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:46:26 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/03 16:31:28 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (1);
	map.map_data = get_map(av[1]);
	set_map(&map);
	map.mlx = mlx_init();
	map.window = mlx_new_window(map.mlx,
			map.width * 64, map.height * 64, "so_long");
	parse_map(&map);
	apply_key(&map);
}
