/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:50:45 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/18 17:52:06 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_all(char *backup)
{
	free(backup);
	return (NULL);
}

char	*create_ret(char *backup)
{
	int		i;
	char	*ret;

	i = ft_strchr(backup, '\n');
	if (i >= 0)
		ret = ft_substr(backup, 0, i + 1);
	else
		ret = ft_substr(backup, 0, ft_strlen(backup) + 1);
	return (ret);
}

char	*ch_init_backup(char *backup)
{
	int		i;

	if (!backup)
		backup = (char *) ft_calloc(1, sizeof(char));
	else
	{
		i = ft_strchr(backup, '\n');
		if (i >= 0)
			backup = ft_substr(backup, i, ft_strlen(backup) - i + 1);
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	int			size;
	char		buf[BUFFER_SIZE + 1];
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ch_init_backup(backup);
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (free_all(backup));
		buf[BUFFER_SIZE] = 0;
		backup = ft_strjoin(backup, buf);
		if (ft_strchr(backup, '\n') >= 0 || size < BUFFER_SIZE)
			break ;
	}
	return (create_ret(backup));
}

int	main(void)
{
	int	fd;

	fd = open("test", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));

	return (0);
}

/*
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

int	ch_buf(char *backup, char *buf)
{
	int		i;
	char	*tmp;

	if (!backup)
		backup = ft_strjoin("", buf);
	else
	{
		tmp = backup;
		backup = ft_strjoin(backup, buf);
		free(tmp);
	}
	return (0);
}

int	ch_backup(char *backup)
{
	int		i;
	char	*tmp;

	i = ft_strchr(backup, '\n');
	if (i >= 0)
	{
		tmp = backup;
		backup = ft_substr(backup, i, ft_strlen(backup) - i + 1);
		free(tmp);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			size;
	char		buf[BUFFER_SIZE + 1];
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup && ch_backup(backup))
		;
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (NULL);
		ch_buf(backup, buf);
		if (ft_strchr(buf, '\n') >= 0 || size < BUFFER_SIZE)
			break ;
	}
	if (ft_strchr(buf, '\n') >= 0)
		return (res_new_line(backup));
	return (res_end_of_file(backup));
}*/