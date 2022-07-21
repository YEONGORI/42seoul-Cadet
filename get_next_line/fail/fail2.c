/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:32:24 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/20 21:04:30 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int BUFFER_SIZE = 16;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*free_all(void **backup);
char	*get_new_ret(char *backup);
char	*ch_init_backup(char *backup);

char	*free_all(void **backup)
{
	if (backup == NULL || *backup == NULL)
		return (NULL);
	free(*backup);
	*backup = NULL;
	return (NULL);
}

char	*get_new_ret(char *backup)
{
	int		idx;
	char	*ret;

	idx = ft_strchr(backup, '\n');
	if (idx == -1)
	{
		ret = ft_substr(backup, 0, ft_strlen(backup));
		if (!ret)
			return (free_all((void **)&backup));
		free_all((void **)&backup);
		return (ret);
	}
	ret = ft_substr(backup, 0, idx + 1);
	if (!ret)
		return (free_all((void **)&backup));
	return (ret);
}

char	*ch_init_backup(char *backup)
{
	int		i;
	char	*tmp;

	if (!backup)
		backup = (char *)ft_calloc(1, sizeof(char));
	else if (ft_strchr(backup, '\n') != -1)
	{
		i = ft_strchr(backup, '\n');
		tmp = backup;
		backup = ft_substr(backup, i + 1, ft_strlen(backup) - i);
		free_all((void **)&tmp);
	}
	if (!backup)
		return (NULL);
	return (backup);
}

char	*get_next_line(int fd)
{
	int			i;
	ssize_t		size;
	char		buf[BUFFER_SIZE + 1];
	static char	*backup;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	backup = ch_init_backup(backup);
	if (!backup)
		return (NULL);
	while (ft_strchr(backup, '\n') == -1 && ++i)
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = 0;
		if (size < 0 || (size == 0 && i == 1))
			return (free_all((void **)&backup));
		if (size < BUFFER_SIZE)
			break ;
		backup = ft_strjoin(backup, buf);
	}
	return (get_new_ret(backup));
}

int	main(void)
{
	int	fd;

	fd = open("test", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s(end)\n", get_next_line(fd));
	printf("%s", get_next_line(fd));
}


/* libft */
/*




밑의 코드는 전부 무시해주셔도 좋습니다!




*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i] != 0)
		str[++j] = s1[i];
	i = -1;
	while (s2[++i] != 0)
		str[++j] = s2[i];
	free((void *)s1);
	return (str);
}
int	ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	tmp;

	i = -1;
	tmp = (unsigned char)c;
	while (s[++i] != 0)
		if (s[i] == tmp)
			return (i);
	return (-1);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	i = -1;
	if (ft_strlen(s) == 0 || start >= ft_strlen(s))
		len = 0;
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	ptr = (char *) ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (++i < len && s[start + i] != 0)
		ptr[i] = s[start + i];
	return (ptr);
}
void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*tmp;
	void			*ptr;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	tmp = (unsigned char *)ptr;
	while (i < count * size)
		tmp[i++] = 0;
	return (ptr);
}
