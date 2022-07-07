void    *ft_memmove(void *dest, const void *src, size_t num)
{
    char        *d;
    const char  *s;

    d = dest;
    s = src;

    if (s < d)
        while (num-- > 0)
            *(d + num) = *(s + num);
    else if (s != d)
        while (num-- > 0)
            *d++ = *s++;
    return (dest);
}