/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:04:44 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/19 16:32:44 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct twll
{
	struct	twll *next;
	struct	twll *prev;
	int		data;
} twll;


#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <unistd.h>

int		init_stack(int ac, char *av[], twll **a);
void	ft_lstadd_front(twll **lst, twll *new);
void	ft_lstadd_back(twll **lst, twll *new);
int		ft_lstclear(twll **lst);
void	ft_lstdelone(twll *lst);
twll	*ft_lstnew(int val);
int	ft_lstsize(twll *lst);

#endif