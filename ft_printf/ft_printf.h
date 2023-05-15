/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:01:03 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 21:06:59 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_strlen(const char *str);
int	ft_putchar(char c);
int	print_ptr(unsigned long long ptr, char *hex, int cnt);

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_ptr(void *addr);
int	ft_print_dec(int n);
int	ft_print_int(int n);
int	ft_print_hex_low(unsigned int n);
int	ft_print_hex_up(unsigned int n);
int	ft_print_und(unsigned int n);

#endif