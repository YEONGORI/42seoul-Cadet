# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	free_ptr(void **ptr)
{
	printf("being freed... %p\n\n", *ptr);
	*ptr = NULL;
	free(*ptr);
}

int main(void)
{
	char	*ptr, *str = "HELLO";

	ptr = (char *) malloc(sizeof(char) * (6));
	strcpy(ptr, str); // str을 ptr에 복사

	printf("before ptr: %s\n", ptr);
	printf("before address: %p\n\n", ptr);

	free_ptr((void **)&ptr);

	printf("after ptr: %s\n", ptr);
	printf("after address: %p\n", ptr);
	return (0);
}