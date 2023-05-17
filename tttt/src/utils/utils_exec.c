/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:39:23 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/17 21:42:43 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_files(t_cmd_managed_list *list)
{
	t_cmd_managed_list	*tmp;

	tmp = list;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		while (tmp->prev)
		{
			close(tmp->fd[0]);
			close(tmp->fd[1]);
			tmp = tmp->prev;
		}
		while (tmp->next)
		{
			close(tmp->fd[0]);
			close(tmp->fd[1]);
			tmp = tmp->next;
		}
		break ;
	}
}
