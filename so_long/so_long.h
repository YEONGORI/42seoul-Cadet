/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:06:26 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/16 12:20:34 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1024

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_pair
{
	int	hei;
	int	wid;
}	t_pair;

typedef struct s_node
{
	t_pair			data;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*back;
	int		count;
}	t_queue;

typedef struct s_map
{
	int		height;
	int		width;
	int		fox_pos_x;
	int		fox_pos_y;
	int		score;
	int		steps;
	int		coin_cnt;

	void	*fox;
	void	*carrot;
	void	*tree;
	void	*hole;
	void	*grass;

	char	**map_data;
	void	*window;
	void	*mlx;
}	t_map;

/* get_next_line */
int			ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlen(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, int len);

/* libft */
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
void		ft_putnbr(int n);

/* map */
void		set_map(t_map *map, int width, int height, int coin);
char		**get_map(char *file);
void		map_checker(char *line_map, char **rect_map);
void		parse_map(t_map *map);

/* key */
void		apply_key(t_map *map);
void		go_up(t_map *map);
void		go_down(t_map *map);
void		go_left(t_map *map);
void		go_right(t_map *map);

int			is_tree(t_map *map);
void		is_hole(t_map *map);
int			is_coin(t_map *map);

/* algorithm */
int			clearable(char **rect, t_pair st, t_pair en, int coin);

/* queue */
void		q_init(t_queue *q);
int			q_is_empty(t_queue *q);
void		q_push(t_queue *q, t_pair data, int init);
void		q_pop(t_queue *q);
int			q_clear(t_queue *q);

/* utils */
void		free_struct(t_map *map);
void		free_char(char	**rect, int max_height);
void		init_char(char	**rect, int m_hei, int m_wid);
t_pair		make_pair(int i, int j);
void		map_error(void);

#endif