/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:46:26 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/26 21:27:13 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include "stdio.h"
int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	void	*mlx_ptr;
	void	*win_ptr;
	char **c = create_map(av[1]);

	printf("%s\n", c[0]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
}
