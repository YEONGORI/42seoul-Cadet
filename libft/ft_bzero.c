/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:14:11 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/08 18:14:52 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
		tmp[i++] = 0;
}
