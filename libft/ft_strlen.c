unsigned long ft_strlen(const char *str){
    long i = 0;
    
    while (str[i] != 0)
        i++;
    return (i);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
    printf("length of GonGonGon %lu\n", ft_strlen("GonGonGon"));
    printf("length of GonGonGon %lu real\n\n", strlen("GonGonGon"));
    return (0);
}*/