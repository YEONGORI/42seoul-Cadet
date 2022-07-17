/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:50:45 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/17 15:10:17 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*res_new_line(char *backup)
{
	char	*res;
	int		i;

	i = ft_strchr_re(backup, '\n');
	res = (char *) malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, backup, i + 2);
	free(backup);
	return (res);
}

char	*res_end_of_file(char *backup)
{
	char	*res;

	res = (char *) malloc(sizeof(char) * (ft_strlen(backup) + 1));
	if (!res)
		return (NULL);
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
	backup = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!backup)
		return (NULL);
	while (1)
	{
		size = read(fd, &buf, BUFFER_SIZE);
		if (size < 0)
			return (NULL);
		backup = ft_strjoin_re(backup, buf);
		if (!backup)
			return (NULL);
		if (ft_strchr_re(buf, '\n') >= 0)
			break ;
		if (size < BUFFER_SIZE)
			break ;
	}
	printf("buf: %s", buf);
	printf("bau: %s", backup);
	printf("idx: %d\n", ft_strchr_re(buf, '\n'));
	if (ft_strchr_re(buf, '\n') >= 0)
		return (res_new_line(backup));
	return (res_end_of_file(backup));
}

int main(void)
{
	int fd = open("test", O_RDONLY);
	printf("%s", get_next_line(fd));
}
