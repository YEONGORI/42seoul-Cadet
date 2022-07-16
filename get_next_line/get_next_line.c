/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:50:45 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/16 18:47:15 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			s_read;
	static char	buf[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ()s_read = read(fd, &buf, BUFFER_SIZE);
}
