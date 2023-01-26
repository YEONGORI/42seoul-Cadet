#include "../push_swap.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = -1;
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++i] != 0)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
