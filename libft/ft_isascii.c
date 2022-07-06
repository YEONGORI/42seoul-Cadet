int ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
    printf("a is ascii? %d\n", ft_isascii('a'));
    printf("a is ascii? %d real\n\n", isascii('a'));
    printf("250 is ascii? %d\n", ft_isascii(250));
    printf("250 is ascii? %d real\n\n", isascii(250));
    return (0);
}*/