/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:22:31 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/16 12:34:00 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

void	free_struct(t_map *map)
{
	int	i;

	i = -1;
	while (map -> map_data[++i])
		free((void *) map -> map_data[i]);
	free((void *) map -> map_data);
	mlx_destroy_image(map -> mlx, map -> fox);
	mlx_destroy_image(map -> mlx, map -> carrot);
	mlx_destroy_image(map -> mlx, map -> tree);
	mlx_destroy_image(map -> mlx, map -> hole);
	mlx_destroy_image(map -> mlx, map -> grass);
	mlx_destroy_window(map -> mlx, map -> window);
}

void	free_char(char	**rect, int max_height)
{
	int	i;

	i = 0;
	while (i < max_height)
		free((void *) rect[i++]);
	free((void *) rect);
}

void	init_char(char	**rect, int m_hei, int m_wid)
{
	int	hei;
	int	wid;

	hei = -1;
	while (++hei < m_hei)
	{
		wid = -1;
		while (++wid < m_wid)
			rect[hei][wid] = 0;
	}
}

t_pair	make_pair(int hei, int wid)
{
	t_pair	p;

	p.hei = hei;
	p.wid = wid;
	return (p);
}

void	map_error(void)
{
	write(2, "Map Error\n", 10);
	exit (EXIT_FAILURE);
}
