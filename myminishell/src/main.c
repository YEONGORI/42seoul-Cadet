/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:41:07 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/12 12:35:19 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add(char *input)
{
	if (ft_strlen(input))
		add_history(input);
}

int	main(int ac, char *av, char ***env)
{
	char					*input;
	t_p_cmd_managed_list	*p_cmd_managed_list;

	(void)av;
	if (ac == 1)
	{
		init_env(env);
		while (1)
		{
			check_signal();
			input = readline("$ ");
			ctrl_d(input);
			add(input);
			if (input && (quotes(input) || empty(input)))
				;
			else
			{
				p_cmd_managed_list = parse(input);
			}
		}
	}
}
