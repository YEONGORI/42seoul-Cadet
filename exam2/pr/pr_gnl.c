#include "pr_gnl.h"

size_t ft_strlen(char *s) {
	int i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char *ft_strchr(char *s, char c) {
	if (*s == c)
		return (s);
	for (int i=0; s[i]; i++)
		if (s[i] == c)
			return (&s[i]);
	return (NULL);
}

char *ft_strjoin(char *s1, char *s2) {
	if (!s1 && !s2)
		return (NULL);
	char *new;
	int i=0, j=0;

	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1 && s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		new[i++] = s2[j++];
	new[i] = 0;
	free(s1);
	return (new);
}

char    *push_line(char *remains)
{
	int		i = 0;
	char	*array;
	
	while (remains[i] && remains[i] != '\n')
		i++;
	if (remains[i] == '\n')
		i++;
	if (!(array = (char *) malloc(sizeof(char) * (i + 1))))
		return (NULL);
	for (i = 0; remains[i] && remains[i] != '\n'; i++)
		array[i] = remains[i];
	if (remains[i] == '\n') {
		array[i] = '\n';
		array[i+1] = 0;
		return (array);
	}
	array[i] = 0;
	return (array);
}

char    *cut_next_line(char *remains)
{
	int		i = 0, j = 0;
	char	*array;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!remains[i]) {
		free(remains);
		return (NULL);
	}
	if (!(array = (char *) malloc(sizeof(char) * (ft_strlen(remains) - i + 1))))
		return (NULL);
	i++;
	while (remains[i])
		array[j++] = remains[i++];
	array[j] = 0;
	free(remains);
	return (array);
}

char	*get_next_line(int fd) {
    if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    static char	*remains;
	char		*line;
    int			count = 1;
    char 		buffer[BUFFER_SIZE + 1];

    buffer[0] = 0;
    while (!ft_strchr(buffer, '\n') && count != 0)
    {
        if ((count = read(fd, buffer, BUFFER_SIZE)) == -1)
            return (NULL);
        buffer[count] = 0;
        remains = ft_strjoin(remains, buffer);
    }
    line = push_line(remains);
    remains = cut_next_line(remains);
	if (line[0] == '\0') 
    {
        free(line);
        return (NULL);
    }
    return (line);
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
}