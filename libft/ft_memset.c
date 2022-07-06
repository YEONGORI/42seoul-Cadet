void *ft_memset(void *dest, int c, size_t count)
{
    size_t i;
    unsigned char uc_c;
    unsigned char * tmp;

    i = 0;
    uc_c = (unsigned char)c;
    tmp = (unsigned char *)dest;
    
    while (i < count)
        tmp[i++] = uc_c;
    return (tmp);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
    char str1[] = "42seoul Is Good";
    char str2[] = "42seoul Is Good";
    char str3[] = "42seoul Is Good";
    char str4[] = "42seoul Is Good";
    int arr1[10];
    int arr2[10];
    printf("fill 6 with '-' %s\n", ft_memset(str1, '-', 6));
    printf("fill 6 with '-' %s real\n\n", memset(str2, '-', 6));

    printf("filled with 0 %s\n", ft_memset(str3, 0, 1));
    printf("filled with 0 %s real\n\n", memset(str4, 0, 1));

    memset(arr1, 5, sizeof(arr1));
    ft_memset(arr2, 5, sizeof(arr2));

    printf("byte check %d\n", arr1[0]);
    printf("byte check %d real\n\n", arr2[0]);
    return (0);
}*/