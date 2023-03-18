#include "pr_gnl.h"

size_t ft_strlen(char *s) {
	int i;
	for (i=0; s[i]; i++)
		;
	return (i);
}

char *ft_strdup(char *s) {
	char *new;

	new = malloc(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (*s)
		*new++ = *s++;
	*new = 0;
	return (new);
}

char *ft_strchr(char *s, char c) {
	if (*s == c)
		return (s);
	while (*s++)
		if (*s == c)
			return (s);
	return (NULL);
}

char *ft_strjoin(char *s1, char *s2) {
	char *res;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = 0;
	return (res);
}

char *ft_substr(char *s, int start, int len) {
	char *new;

	new = malloc(len + 1);
	while (start--);
		s++;
	while (len-- && *s)
		*new++ = *s++;
	*new = 0;
	return (new);
}

int	get_next_line(char **line) {
	static char	*s;
	char		buf[1025];
	char		*pos, *tmp;
	int			ret;

	if (!line || (!s && !(s == ft_strdup(""))))
		return (-1);
	while ((pos = ft_strchr(s, '\n')) == 0)
	{
		if ((ret = read(0, buf, 1024)) == 0)
			break;
		buf[ret] = 0;
		tmp = s;
		if ((s = ft_strjoin(s, buf)) == 0)
			return (-1);
		free(tmp);
	}
	if (pos)
	{
		*line = ft_substr(s, 0, pos -s);
	}
}