#include "stdlib.h"
#include "unistd.h"
#define BUFF_SIZE 1025

int		ft_strlen(char *s) {
	if (!s)
		return 0;
	int i=0;
	while (s[i])
		i++;
	return (i);
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
	int 	i=0, j=0;
	char	*new;

	new = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return NULL;
	while (s1 && s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		new[i++] = s2[j++];
	new[j] = 0;
	return new;
}

char	*push_line(char *s) {
	if (!s)
		return NULL;
	int 	i=0;
	char	*new;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	new = malloc(sizeof(char) * (i+1));
	if (!new)
		return NULL;
	i=-1;
	while (s[++i] && s[i] != '\n')
		new[i] = s[i];
	if (s[i] == '\n') {
		s[i] = '\n';
		s[i + 1] = 0;
		return s;
	}
	s[i] = 0;
	return s;
}

char	*cut_next_line(char *s) {
	if (!s)
		return NULL;
	int 	i=0;
	char	*new;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i]) {
		free(s);
		return NULL;
	}
	new = malloc(sizeof(char) * ((ft_strlen(s) - i + 1)));
	if (!new)
		return NULL;
	i++;
	int j=0;
	while (s[i])
		new[j++] = s[i++];
	new[j] = 0;
	free(s);
	return new;
}

char	*get_next_line(int fd) {
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFF_SIZE <= 0)
		return NULL;
	
	int cnt = 1;
	static char	*s;
	char		buf[BUFF_SIZE + 1];
	char		*line;

	while (!ft_strchr(s, '\n') && cnt != 0) {
		if ((cnt = read(fd, buf, BUFF_SIZE) < 0))
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