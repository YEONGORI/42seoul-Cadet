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

static int is_continue(char **rect, char **vis, t_pair tmp)
{
    int max_x;
    int max_y;

    max_x = ft_strlen(rect[0]);
    max_y = 0;
    while (rect[max_y])
        max_y++;
    if (vis[tmp.x][tmp.y] || rect[tmp.x][tmp.y] == '1')
        return (1);
    else if (tmp.x < 0 || tmp.y < 0 || tmp.x >= max_x || tmp.y >= max_y)
        return (1);
    else
        return (0);
}

static t_pair go_every_direction(t_pair cur, int i)
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

static int go_endpoint(char **rect, char **vis, t_pair st, t_pair en)
{
    int i;
    t_pair tmp;
    t_pair cur;
    t_stack *s;

    s_init(s);
    s_push(s, st);
    vis[st.x][st.y] = 1;
    while (!s_isempty(s))
    {
        cur = s->top->data;
        s_pop(s);
        i = -1;
        while (++i < 4)
        {
            tmp = go_every_direction(cur, i);
            printf("cur x y: [%d, %d]\n", tmp.x, tmp.y);
            if (is_continue(rect, vis, tmp))
                continue;
            if (tmp.x == en.x && tmp.y == en.y)
                return (1);
            s_push(s, tmp);
            vis[tmp.x][tmp.y] = 1;
        }
    }
    return (coin_cnt);
}

static int is_obtain(char **rect, char **vis, t_pair st, int coin_cnt)
{
    int i;
    t_pair tmp;
    t_pair cur;
    t_stack *s;

    s_init(s);
    s_push(s, st);
    vis[st.x][st.y] = 1;
    while (!s_isempty(s))
    {
        cur = s->top->data;
        s_pop(s);
        i = -1;
        while (++i < 4)
        {
            tmp = go_every_direction(cur, i);
            printf("cur x y: [%d, %d]\n", tmp.x, tmp.y);
            if (is_continue(rect, vis, tmp))
                continue;
            if (rect[tmp.x][tmp.y] == 'C')
                coin_cnt++;
            s_push(s, tmp);
            vis[tmp.x][tmp.y] = 1;
        }
    }
    return (0);
}

int clearable(char **rect, t_pair st, t_pair en, int coin)
{
    int i;
    int width;
    int height;
    char **vis;
    printf("end x y: [%d, %d]\n", en.x, en.y);
    i = -1;
    width = ft_strlen(rect[0]);
    height = -1;
    while (rect[++height])
        ;
    vis = (char **)ft_calloc((size_t)height, sizeof(char *));
    while (++i < height)
        vis[i] = (char *)ft_calloc((size_t)width, sizeof(char));
    if (go_endpoint(rect, vis, st, en))
        return (0);
    free_char(vis);
    i = -1;
    vis = (char **)ft_calloc((size_t)height, sizeof(char *));
    while (++i < height)
        vis[i] = (char *)ft_calloc((size_t)width, sizeof(char));
    if (is_obtain(rect, vis, 0) != coin)
        return (0);
    return (1);
}
