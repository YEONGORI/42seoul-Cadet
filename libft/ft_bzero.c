void ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char *tmp;

    i = 0;
    tmp = (unsigned char *)s;
    while (i < n)
        tmp[i++] = 0;
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
    char str1[] = "hello cadet";
    char str2[] = "hello cadet";

    bzero(str1, 3);
    printf("bzero result: %s\n", str1);

    ft_bzero(str2, 3);
    printf("ft_bzero result: %s\n", str2);

    return (0);
}*/