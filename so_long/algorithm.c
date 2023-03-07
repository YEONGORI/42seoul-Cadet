/* ************************************************************************** */
/*								                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:49:16 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/07 09:30:09 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_continue(char **rect, char **vis, t_pair tmp)
{
	int	m_wid;
	int	m_hei;

	m_wid = ft_strlen(rect[0]);
	m_hei = 0;
	while (rect[m_hei])
		m_hei++;
	if (vis[tmp.hei][tmp.wid] || rect[tmp.hei][tmp.wid] == '1')
		return (1);
	else if (tmp.wid < 0 || tmp.hei < 0 || tmp.wid >= m_wid || tmp.hei >= m_hei)
		return (1);
	else
		return (0);
}

static t_pair	go_every_direction(t_pair cur, int i)
{
	if (i == 0)
		cur.wid -= 1;
	else if (i == 1)
		cur.wid += 1;
	else if (i == 2)
		cur.hei -= 1;
	else if (i == 3)
		cur.hei += 1;
	return (cur);
}

static int	go_endpoint(char **rect, char **vis, t_pair st, t_pair en)
{
	int		i;
	t_pair	tmp;
	t_pair	cur;
	t_queue	q;

	q_push(&q, st, 1);
	vis[st.hei][st.wid] = 1;
	while (!q_is_empty(&q))
	{
		cur = q.front->data;
		q_pop(&q);
		i = -1;
		while (++i < 4)
		{
			tmp = go_every_direction(cur, i);
			if (is_continue(rect, vis, tmp))
				continue ;
			if (tmp.wid == en.wid && tmp.hei == en.hei)
				return (q_clear(&q));
			q_push(&q, tmp, 0);
			vis[tmp.hei][tmp.wid] = 1;
		}
	}
	q_clear(&q);
	return (0);
}

static int	is_obtain(char **rect, char **vis, t_pair st, int coin_cnt)
{
	int		i;
	t_pair	tmp;
	t_pair	cur;
	t_queue	q;

	q_push(&q, st, 1);
	vis[st.hei][st.wid] = 1;
	while (!q_is_empty(&q))
	{
		cur = q.front->data;
		q_pop(&q);
		i = -1;
		while (++i < 4)
		{
			tmp = go_every_direction(cur, i);
			if (is_continue(rect, vis, tmp))
				continue ;
			if (rect[tmp.hei][tmp.wid] == 'C')
				coin_cnt++;
			q_push(&q, tmp, 0);
			vis[tmp.hei][tmp.wid] = 1;
		}
	}
	q_clear(&q);
	return (coin_cnt);
}

int	clearable(char **rect, t_pair st, t_pair en, int coin)
{
	int		i;
	int		cnt;
	int		width;
	int		height;
	char	**vis;

	i = -1;
	width = ft_strlen(rect[0]);
	height = 0;
	while (rect[height])
		height++;
	vis = (char **)ft_calloc((size_t)height, sizeof(char *));
	while (++i < height)
		vis[i] = (char *)ft_calloc((size_t)width, sizeof(char));
	if (!go_endpoint(rect, vis, st, en))
	{
		free_char(vis, height);
		return (0);
	}
	init_char(vis, height, width);
	cnt = is_obtain(rect, vis, st, 0);
	free_char(vis, height);
	if (cnt != coin)
		return (0);
	return (1);
}
