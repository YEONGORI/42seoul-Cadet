/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:42:45 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/16 16:58:06 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int snum)
{
	static int				i;
	static unsigned char	c;

	c |= (snum == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	act;

	write(1, "SERVER PID : ", 13);
	ft_putnbr((int) getpid());
	write(1, "\n", 1);
	act.sa_handler = sig_handler;
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
