void *ft_memcpy(void *dest, const void *src, size_t num)
{
    size_t              i;
    unsigned char       *d;
    unsigned const char *s;

    i = -1;
    d = dest;
    s = src;
    if (num == 0 || dest == src)
        return (dest);
    if (dest == NULL && src == NULL)
        return (NULL);
    while (++i < num)
        d[i] = s[i];
    return (dest);
}

/*
// 메모리는 1바이트씩 이니까 unsigned char형태로 참조를 하면 1바이트씩 참조를 한다.
// 따라서 int형이 오더라도 메모리 복사이기때문에 상관이 없다.
#include <stdio.h>
#include <string.h>
int main(void)
{
    int arr1[] = {1,2,3,4,5};
    int arr2[5];
    int arr3[] = {1,2,3,4,5};
    int arr4[5];

    char str1[] = "Hello Cadet!";
    char str2[13];
    char str3[] = "Hello Cadet!";
    char str4[13];

    ft_memcpy(arr2, arr1, sizeof(int) * 5);
    printf("ft_memcpy result: ");
    for (int i=0;i<5;i++)
        printf("%d ", arr2[i]);

    memcpy(arr4, arr3, sizeof(int) * 5);
    printf("\nmemcpy result: ");
    for (int i=0;i<5;i++)
        printf("%d ", arr4[i]);

    ft_memcpy(str2, str1, strlen(str1) + 1);
    printf("\n\nft_memcpy result: %s\n", str2);

    memcpy(str4, str3, strlen(str3) + 1);
    printf("memcpy result: %s\n", str4);

    return (0);
}*/