int ft_isalnum(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    else if (c >= 'a' && c <= 'z')
        return (1);
    else if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

/*
#include "libft.h"
int main(void)
{
    printf("C is alnum? %d\n", ft_isalnum('C'));
    printf("C is alnum? %d real\n\n", isalnum('C'));

    printf("c is alnum? %d\n", ft_isalnum('c'));
    printf("c is alnum? %d real\n\n", isalnum('c'));

    printf("7 is alnum? %d\n", ft_isalnum('7'));
    printf("7 is alnum? %d real\n\n", isalnum('7'));

    printf("# is alnum? %d\n", ft_isalnum('#'));
    printf("# is alnum? %d real\n\n", isalnum('#'));
}*/