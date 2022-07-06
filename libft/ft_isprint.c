int ft_isprint(int c)
{
    if (c >= 32 && c <= 127)
        return (1);
    return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
    printf("~ isprint? %d\n", ft_isprint('~'));
    printf("~ isprint? %d real\n\n", isprint('~'));
    printf("\\n isprint? %d\n", ft_isprint('\n'));
    printf("\\n isprint? %d real\n\n", isprint('\n'));
    return (0);
}*/