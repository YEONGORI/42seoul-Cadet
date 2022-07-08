/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:18:17 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/08 18:18:54 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t			i;
	unsigned char	uc_c;
	unsigned char	*tmp;

	i = 0;
	uc_c = (unsigned char)c;
	tmp = (unsigned char *)dest;

	while (i < count)
		tmp[i++] = uc_c;
	return (tmp);
}
