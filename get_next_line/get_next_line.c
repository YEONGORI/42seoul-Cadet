/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:50:45 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/18 12:54:09 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_all(char *backup)
{
	free(backup);
	return (NULL);
}

char	*res_new_line(char *backup)
{
	char	*res;
	int		i;

	i = ft_strchr_re(backup, '\n');
	res = (char *) ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (free_all(backup));
	ft_strlcpy(res, backup, i + 2);
	free(backup);
	return (res);
}

char	*res_end_of_file(char *backup)
{
	char	*res;

	res = (char *) ft_calloc(ft_strlen(backup) + 1, sizeof(char));
	if (!res)
		return (free_all(backup));
	ft_strlcpy(res, backup, ft_strlen(backup));
	free(backup);
	return (res);
}

char	*get_next_line(int fd)
{
	int			size;
	char		buf[BUFFER_SIZE + 1];
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!backup)
		return (NULL);
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (free_all(backup));
		backup = ft_strjoin_re(backup, buf);
		if (!backup)
			return (free_all(backup));
		if (ft_strchr_re(buf, '\n') >= 0 || size < BUFFER_SIZE)
			break ;
	}
	if (ft_strchr_re(buf, '\n') >= 0)
		return (res_new_line(backup));
	return (res_end_of_file(backup));
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int fd = open("test", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	return (0);
}