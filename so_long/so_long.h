/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:06:26 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/27 13:10:20 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h> // 삭제 예정

typedef struct s_map
{
	int		height;
	int		width;
	int		fox_pos_x;
	int		fox_pos_y;
	int		score;
	int		steps;

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
char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlen(const char *str);
void		*ft_calloc(size_t count, size_t size);

/* libft */
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);

/* map */
char		**create_map(char *file);
int			map_checker(char *line_map, char **rect_map);
void		parse_map(t_map *map);


#endif