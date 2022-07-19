/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:50:45 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/19 16:23:52 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_ret(char *backup, int size)
{
	int		i;
	char	*ret;

	if (!backup)
		return (NULL);
	if (!ft_strlen(backup) && !size)
	{
		free(backup);
		return (NULL);
	}
	i = ft_strchr(backup, '\n');
	if (i >= 0)
		ret = ft_substr(backup, 0, i + 1, 0);
	else
		ret = ft_substr(backup, 0, ft_strlen(backup), 1);
	if (!ret)
		return (NULL);
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
			backup = ft_substr(backup, i + 1, ft_strlen(backup) - i + 1, 1);
	}
	if (!backup)
		return (NULL);
	return (backup);
}

char	*get_next_line(int fd)
{
	int			size;
	char		buf[BUFFER_SIZE + 1];
	static char	*backup;

	size = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ch_init_backup(backup);
	while (backup)
	{
		if (ft_strchr(backup, '\n') >= 0 || size < BUFFER_SIZE)
			break ;
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
		{
			free(backup);
			return (NULL);
		}
		buf[size] = 0;
		backup = ft_strjoin(backup, buf);
	}
	return (create_ret(backup, size));
}