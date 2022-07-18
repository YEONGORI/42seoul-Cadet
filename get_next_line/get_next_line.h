/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:50:43 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/18 12:51:43 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*ft_strjoin_re(char const *s1, char const *s2);
int		ft_strchr_re(const char *s, int c);
size_t	ft_strlen(const char *str);
void	ft_strlcpy(char *dest, const char *src, size_t datsize);
void	*ft_calloc(size_t count, size_t size);

#endif