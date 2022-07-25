/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:01:03 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/25 21:13:45 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c);
int print_ptr(unsigned long long ptr, char *hex, int cnt);

#endif