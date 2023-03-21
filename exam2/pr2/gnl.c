#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1025

int		ft_strlen(char *s) {
	if (!s)
		return 0;
	int i = 0;
	while (s[i])
		i++;
	return i;
}

char	*ft_strchr(char *s, char c) {
	if (*s == c)
		return s;
	for (int i=0; s[i]; i++)
		if (s[i] == c)
			return &s[i];
	return NULL;
}

char	*ft_strjoin(char *s1, char *s2) {
	if (!s1 && !s2)
		return NULL;
	char	*new;
	int		i = 0, j = 0;

	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return NULL;
	for (j=0; s1 && s1[j]; j++)
		new[i++] = s1[j];
	for (j=0; s2 && s2[j]; j++)
		new[i++] = s2[j];
	new[i] = 0;
	free(s1);
	return new;
}

char	*push_line(char *s) {
	if (!s)
		return NULL;
	int 	i=0;
	char	*new;

	for (i=0; s[i] && s[i] != '\n'; i++)
		;
	if (s[i] == '\n')
		i++;
	if (!(new = (char *)malloc(sizeof(char) * (i + 1))))
		return NULL;
	for (i=0; s[i] && s[i] != '\n'; i++)
		new[i] = s[i];
	if (s[i] == '\n') {
		new[i] = '\n';
		new[i+1] = 0;
		return new;
	}
	new[i] = 0;
	return new;
}

char	*cut_next_line(char *s) {
	if (!s)
		return NULL;
	int		i = 0;
	char	*new;
	for (i=0; s[i] && s[i] != '\n'; i++)
		;
	if (!s[i]) {
		free(s);
		return NULL;
	}
	if (!(new = malloc(sizeof(char) * (ft_strlen(s) - i + 1))))
		return NULL;
	i++;
	int j=0;
	for (j=0; s[i]; j++)
		new[j] = s[i++];
	new[j] = 0;
	free(s);
	return new;
}

char	*get_next_line(int fd) {
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFF_SIZE <= 0)
		return NULL;

	int			cnt = 1;
	static char *s;
	char		*line;
	char		buf[BUFF_SIZE + 1] = {0};

	while (!ft_strchr(buf, '\n') && cnt != 0) {
		if ((cnt = read(fd, buf, BUFF_SIZE)) == -1)
			return NULL;
		buf[cnt] = 0;
		s = ft_strjoin(s, buf);
	}
	line = push_line(s);
	s = cut_next_line(s);
	if (line[0] == 0) {
		free(line);
		return NULL;
	}
	return line;
}

#include "fcntl.h"
#include "stdio.h"
int main(void)
{
	int fd = open("test", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// close(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}