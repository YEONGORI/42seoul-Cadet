int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

/*
#include "libft.h"
int main(void)
{
    printf("A is digit? %d\n", ft_isdigit('A'));
    printf("A is digit? %d\n\n", isdigit('A'));
    
    printf("8 is digit? %d\n", ft_isdigit('8'));
    printf("8 is digit? %d\n\n", isdigit('8'));

    return (0);
}*/