/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:22:31 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/07 13:38:19 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

void	show_steps(t_map *map)
{
	mlx_put_image_to_window(map -> mlx, map -> window, map -> tree, 0, 0);
	mlx_string_put(map->mlx, map->window, 32, 32, 0x000000ff,
		ft_itoa(map -> steps));
}

void	free_struct(t_map *map)
{
	int	i;

	i = -1;
	while (map -> map_data[++i])
		free((void *) map -> map_data[i]);
	free((void *) map -> map_data);
	free((void *) map -> fox);
	free((void *) map -> carrot);
	free((void *) map -> tree);
	free((void *) map -> hole);
	free((void *) map -> grass);
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
