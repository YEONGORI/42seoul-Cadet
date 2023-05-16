/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:10:18 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 21:12:55 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execution(t_p_cmd_managed_list *list)
{
	int						status;
	t_p_cmd_managed_list	*prev;

	prev = list;
	if (single_cmd(list))
		return ;
}