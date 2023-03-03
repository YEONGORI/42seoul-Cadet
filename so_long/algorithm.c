/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:49:16 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/03 18:09:12 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_pair	go_every_direction(t_pair cur, int i)
{
	if (i == 0)
		cur.x -= 1;
	else if (i == 1)
		cur.x += 1;
	else if (i == 3)
		cur.y -= 1;
	else if (i == 4)
		cur.y += 1;
	return (cur);
}

static int	dfs(char **rect, char **vis, t_pair st, t_pair en)
{
	int		i;
	t_pair	tmp;
	t_pair	cur;
	t_stack	*s;

	s_init(s);
	s_push(s, st);
	vis[st.x][st.y] = 1;
	while (!s_isempty(s))
	{
		cur = s -> top -> data;
		s_pop(s);
		i = -1;
		while (++i < 4)
		{
			tmp = go_every_direction(cur, i);
			if (vis[tmp.x][tmp.y] || rect[tmp.x][tmp.y] == '1')
				continue ;
			if (tmp.x == en.x && tmp.y == en.y)
				return (1);
			s_push(s, tmp);
			vis[tmp.x][tmp.y] = 1;
		}
	}
	return (0);
}

int	clearable(char **rect, t_pair st, t_pair en, int coin)
{
	int		i;
	int		res;
	int		width;
	int		height;
	char	**vis;

	i = -1;
	width = ft_strlen(rect[0]);
	height = -1;
	while (rect[++height])
		;
	vis = (char **) ft_calloc((size_t) height, sizeof(char *));
	while (++i < height)
		vis[i] = (char *) ft_calloc((size_t) width, sizeof(char));
	res = dfs(rect, vis, st, en);
	free_char(vis);
	return (res);
}
