/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:46:26 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/26 22:07:28 by yeongele         ###   ########.fr       */
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
	map.map_data = create_map(av[1]);
	map.mlx = mlx_init();
	map.window = mlx_new_window(map.mlx, \
	(map.width + 1) * 50, (map.height + 1) * 50, "so_long");
}
