/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:50:45 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/17 13:31:13 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*make_result(char *backup, int eol)
{
	int		i;
	char	*res;

	i = -1;
	res = (char *) malloc(sizeof(char) * (eol + 1));
	if (!res)
		return (NULL);
	while (++i <= eol)
		res[i] = backup[i];
	res[i] = 0;
	free(backup);
	return (res);
}

static int	ch_new_line(char *backup)
{
	int	i;

	i = -1;
	while (++i)
		if (backup[i] == '\n' || backup[i] == '\0')
			return (i);
	return (0);
}

char	*get_next_line(int fd)
{
	int			size;
	char		buf[BUFFER_SIZE + 1];
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	size = read(fd, &buf, BUFFER_SIZE);
	while (size >= 0)
	{
		backup = ft_strjoin(backup, buf);
		if (backup == NULL)
			return (NULL);
		size = ch_new_line(backup);
		printf("hi");
		if (size > 0)
			return (make_result(backup, size));
		size = read(fd, &buf, BUFFER_SIZE);
	}
	return (NULL);
}


int main(void)
{
	int fd = open("test", O_RDONLY);
	printf("%d\n", fd);
	printf("%s", get_next_line(fd));
}