/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:49:34 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/17 10:49:35 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char c, int *sign)
{
	if (c != '+' && c != '-' && !((c >= 9 && c <= 13) || c == 32) \
	&& !(c >= '0' && c <= '9'))
		return (-1);
	if (c == '+' || c == '-')
	{
		if (*sign != 44)
			return (-1);
		*sign -= c;
	}
	return (0);
}

long long	ft_atoi_ch(const char *str, int sign)
{
	long long	res;

	res = 0;
	if (sign != 44 && sign != 1)
		sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *(str++) - '0';
		if (res >= 999999999999999999)
			return (-1);
		else if (res * sign <= -99999999999999999)
			return (0);
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 44;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] != 0)
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (0);
		if (check(str[i], &sign) < 0)
			return (0);
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = ft_atoi_ch(str + i, sign);
			break ;
		}
		i++;
	}
	return (res * (sign / 44 + sign % 44));
}
