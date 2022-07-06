/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:31:09 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/06 12:31:11 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    
    return (0);
}

/*
#include "libft.h"
int main(void)
{
    printf("A is alpha? %d\n", ft_isalpha('A'));
    printf("A is alpha? %d real\n\n", isalpha('A'));

    printf("a is alpha? %d\n", ft_isalpha('a'));
    printf("a is alpha? %d real\n\n", isalpha('a'));

    printf("0 is alpha? %d\n", ft_isalpha('8'));
    printf("0 is alpha? %d real\n\n", isalpha('8'));

    return (0);
}*/