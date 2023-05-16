/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:41:07 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 21:21:59 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int ac, char **av, char **env)
{
	char				*input;
	t_cmd_managed_list	*cmd_managed_list;

	(void)av;
	if (ac == 1)
	{
		init_env(env);
		ch_signal();
		while (1)
		{
			input = readline("$ ");
			ctrl_d(input);
			if (ft_strlen(input))
				add_history(input);
			if (input && !ch_quotes(input) && !ch_empty(input))
			{
				cmd_managed_list = parsing(input);
			}
			free(input);
		}
	}
}
