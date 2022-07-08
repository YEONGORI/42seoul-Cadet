#include "tester.h"

const char	*src1 = "This is Good to 42!!";
const char	*src2 = "";
const char	*src3 = " ";
const char	*src4 = "1234567890";
const char	*src5 = "1+2+3+4+5+6+7+8+9+10 = 42";

const int src_i1[10] = {1,2,3,4,5,6,7,8,9,0};
const int src_i2[10] = {2,4,1,9,7,8,3,6,0,5};

void test_ft_isalpah(void) {
	printf("ft_isalpha A: %d\n", ft_isalpha('A'));
	printf("isalpha a: %d\n", isalpha('A'));

	printf("ft_isalpha a: %d\n", ft_isalpha('a'));
	printf("isalpha a: %d\n", isalpha('a'));

	printf("ft_isalpha 8: %d\n", ft_isalpha('8'));
	printf("isalpha 8: %d\n", isalpha('8'));
}
void test_ft_isdigit(void) {
	printf("ft_isdigit A: %d\n", ft_isdigit('A'));
	printf("isdigit A: %d\n", isdigit('A'));

	printf("ft_isdigit 8: %d\n", ft_isdigit('8'));
	printf("isdigit 8: %d\n", isdigit('8'));
}
void test_ft_isalnum(void) {
	printf("ft_isalnum C: %d\n", ft_isalnum('C'));
	printf("isalnum C: %d\n", isalnum('C'));

	printf("ft_isalnum c: %d\n", ft_isalnum('c'));
	printf("isalnum c: %d\n", isalnum('c'));

	printf("ft_isalnum 7: %d\n", ft_isalnum('7'));
	printf("isalnum 7: %d\n", isalnum('7'));

	printf("ft_isalnum #: %d\n", ft_isalnum('#'));
	printf("isalnum #: %d\n", isalnum('#'));
}
void test_ft_isascii(void) {
	printf("ft_isascii a: %d\n", ft_isascii('a'));
	printf("isascii a: %d\n", isascii('a'));
	printf("ft_isascii 250: %d\n", ft_isascii(250));
	printf("isascii 250: %d\n", isascii(250));
}
void test_ft_isprint(void) {
	printf("ft_isprint 1: %d\n", ft_isprint(1));
	printf("isprint \\n: %d\n", isprint(10));
}
void test_ft_strlen(void) {
	printf("ft_strlen length of GonGonGon: %lu\n", ft_strlen("GonGonGon"));
	printf("strlen length of GonGonGon: %lu\n", strlen("GonGonGon"));
}
void test_ft_memset(void) {
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
}
void test_ft_bzero(void) {
    char str1[] = "hello cadet";
    char str2[] = "hello cadet";

    bzero(str1, 3);
    printf("bzero result: %s\n", str1);

    ft_bzero(str2, 3);
    printf("ft_bzero result: %s\n", str2);
}
void test_ft_memcpy(void) {
    // 메모리는 1바이트씩 이니까 unsigned char형태로 참조를 하면 1바이트씩 참조를 한다.
    // 따라서 int형이 오더라도 메모리 복사이기때문에 상관이 없다.
	int dest_i1[10];
	int dest_i2[10];

	char dest1[42];
    char dest2[42];

    ft_memcpy(dest_i1, src_i1, sizeof(int) * 5);
    printf("ft_memcpy result: ");
    for (int i=0;i<5;i++)
        printf("%d ", dest_i1[i]);

    memcpy(dest_i2, src_i1, sizeof(int) * 5);
    printf("\nmemcpy result: ");
    for (int i=0;i<5;i++)
        printf("%d ", dest_i2[i]);

    ft_memcpy(dest1, src1, strlen(src1) + 1);
    printf("\nft_memcpy result: %s\n", dest1);

    memcpy(dest2, src1, strlen(src2) + 1);
    printf("memcpy result: %s\n", dest2);
}
void test_ft_memmove(void) {
	char dest1[42];
	char dest2[42];

	ft_memmove(dest1, src1, 13);
	memmove(dest2, src1, 13);

	printf("ft_memmove: %s\n", dest1);
	printf("memmove: %s\n", dest2);
}
void test_ft_strlcpy(void) {
	char dest1[42];
	char dest2[42];

	ft_strlcpy(dest1, src1, 0);
	strlcpy(dest2, src1, 0);

	printf("ft_strlcpy: %s\n", dest1);
	printf("strlcpy: %s\n", dest2);
}
void test_ft_strlcat(void) {
	char	dest1[100] = {'W','h','o',' ','a', 'i', '?', ':', '\0'};
	char	dest2[100] = {'W','h','o',' ','a', 'i', '?', ':', '\0'};
	char	dest3[100] = {};
	char	dest4[100] = {};

	ft_strlcat(dest1, src1, 30);
	strlcat(dest2, src1, 30);
	ft_strlcat(dest3, src2, 8);
	ft_strlcat(dest4, src2, 8);
	printf("ft_strlcat: %s\n", dest1);
	printf("strlcat: %s\n", dest2);

	printf("ft_strlcat: %s\n", dest3);
	printf("strlcat: %s\n", dest4);
}
void test_ft_toupper(void) {
	printf("ft_toupper A: %c\n", (char)(ft_toupper('A')));
	printf("toupper A: %c\n", (char)(toupper('A')));

	printf("ft_toupper a: %c\n", (char)(ft_toupper('a')));
	printf("toupper a: %c\n", (char)(toupper('a')));

	printf("ft_toupper \\n: %c\n", (char)(ft_toupper('\n')));
	printf("toupper \\n: %c\n", (char)(toupper('\n')));
}
void test_ft_tolower(void) {
	printf("ft_tolower A: %c\n", (char)(ft_tolower('A')));
	printf("tolower A: %c\n", (char)(tolower('A')));

	printf("ft_tolower a: %c\n", (char)(ft_tolower('a')));
	printf("tolower a: %c\n", (char)(tolower('a')));

	printf("ft_tolower \\n: %c\n", (char)(ft_tolower('\n')));
	printf("tolower \\n: %c\n", (char)(tolower('\n')));
}
void test_ft_strchr(void) {
	printf("ft_strchr: %s\n", ft_strchr(src1, 'i'));
	printf("strchr: %s\n", strchr(src1, 'i'));

	printf("ft_strchr: %s\n", ft_strchr(src1, '\0'));
	printf("strchr: %s\n", strchr(src1, '\0'));
}
void test_ft_strrchr(void) {
	printf("ft_strrchr: %s\n", ft_strrchr(src1, 'i'));
	printf("strrchr: %s\n", strrchr(src1, 'i'));

	printf("ft_strrchr: %s\n", ft_strrchr(src1, '\0'));
	printf("strrchr: %s\n", strrchr(src1, '\0'));
}
void test_ft_strncmp(void) {
	printf("ft_strncmp: %d\n", ft_strncmp("This is Same", "This is same", 6));
	printf("strncmp: %d\n", strncmp("This is Same", "This is same", 6));

	printf("ft_strncmp: %d\n", ft_strncmp("This is Same", "This is same", 10));
	printf("strncmp: %d\n", strncmp("This is Same", "This is same", 10));

	printf("ft_strncmp: %d\n", ft_strncmp("This is same", "This is Same", 10));
	printf("strncmp: %d\n", strncmp("This is same", "This is Same", 10));

	printf("ft_strncmp: %d\n", ft_strncmp("Zero", "Zero", 0));
	printf("strncmp: %d\n", strncmp("Zero", "Zero", 0));
}
void test_ft_memchr(void) {
	printf("ft_memchr: %p\n", ft_memchr(src1, 'G', 20));
	printf("memchr: %p\n", memchr(src1, 'G', 20));

	printf("ft_memchr: %p\n", ft_memchr(src1, 'Q', 20));
	printf("memchr: %p\n", memchr(src1, 'Q', 20));

	printf("ft_memchr: %p\n", ft_memchr(src1, 'i', 0));
	printf("memchr: %p\n", memchr(src1, 'i', 0));
}
void test_ft_memcmp(void) {
	printf("ft_memcmp: %d\n", ft_memcmp("This is Same", "This is same", 6));
	printf("memcmp: %d\n", memcmp("This is Same", "This is same", 6));

	printf("ft_memcmp: %d\n", ft_memcmp("This is Same", "This is same", 10));
	printf("memcmp: %d\n", memcmp("This is Same", "This is same", 10));

	printf("ft_memcmp: %d\n", ft_memcmp("This is same", "This is Same", 10));
	printf("memcmp: %d\n", memcmp("This is same", "This is Same", 10));

	printf("ft_memcmp: %d\n", ft_memcmp("Zero", "Zero", 0));
	printf("memcmp: %d\n", memcmp("Zero", "Zero", 0));
}
void test_ft_strnstr(void) {
	printf("ft_strnstr: %s\n", ft_strnstr("This is Good to Cadet!", "to", 20));
	printf("strnstr: %s\n", strnstr("This is Good to Cadet!", "to", 20));

	printf("ft_strnstr: %s\n", ft_strnstr("This is Good to Cadet!", "t", 0));
	printf("strnstr: %s\n", strnstr("This is Good to Cadet!", "t", 0));

	printf("ft_strnstr: %s\n", ft_strnstr("", "t", 20));
	printf("strnstr: %s\n", strnstr("", "t", 20));

	printf("ft_strnstr: %s\n", ft_strnstr("This is Good to Cadet!", "", 20));
	printf("strnstr: %s\n", strnstr("This is Good to Cadet!", "", 20));

	printf("ft_strnstr: %s\n", ft_strnstr("This is Good to Cadet!", "tq", 20));
	printf("strnstr: %s\n", strnstr("This is Good to Cadet!", "tq", 20));
}
// void test_ft_atoi(void);

int main(void)
{
    /* Test ft_isalpha */
    printf("\n\n----- Test ft_isalpha -----\n");
    test_ft_isalpah();

    /* Test ft_isdigit */
    printf("\n\n----- Test ft_isdigit -----\n");
    test_ft_isdigit();

    /* Test ft_isalnum */
    printf("\n\n----- Test ft_isalnum -----\n");
    test_ft_isalnum();

    /* Test ft_isascii */
    printf("\n\n----- Test ft_isascii -----\n");
    test_ft_isascii();

    /* Test ft_isprint */
    printf("\n\n----- Test ft_isprint -----\n");
    test_ft_isprint();

    /* Test ft_strlen */
    printf("\n\n----- Test ft_strlen -----\n");
    test_ft_strlen();

    /* Test ft_memset */
    printf("\n\n----- Test ft_memset -----\n");
    test_ft_memset();

    /* Test ft_bzero */
    printf("\n\n----- Test ft_bzero -----\n");
    test_ft_bzero();

    /* Test ft_memcpy */
    printf("\n\n----- Test ft_memcpy -----\n");
    test_ft_memcpy();

    /* Test ft_memmove */
    printf("\n\n----- Test ft_memmove -----\n");
    test_ft_memmove();

    /* Test ft_strlcpy */
    printf("\n\n----- Test ft_strlcpy -----\n");
    test_ft_strlcpy();

    /* Test ft_strlcat */
    printf("\n\n----- Test ft_strlcat -----\n");
    test_ft_strlcat();

    /* Test ft_toupper */
    printf("\n\n----- Test ft_toupper -----\n");
    test_ft_toupper();

    /* Test ft_tolower */
    printf("\n\n----- Test ft_tolower -----\n");
    test_ft_tolower();

    /* Test ft_strchr */
    printf("\n\n----- Test ft_strchr -----\n");
    test_ft_strchr();

    /* Test ft_strrchr */
    printf("\n\n----- Test ft_strrchr -----\n");
    test_ft_strrchr();

    /* Test ft_strncmp */
    printf("\n\n----- Test ft_strncmp -----\n");
    test_ft_strncmp();

    /* Test ft_memchr */
    printf("\n\n----- Test ft_memchr -----\n");
    test_ft_memchr();

    /* Test ft_memcmp */
    printf("\n\n----- Test ft_memcmp -----\n");
    test_ft_memcmp();

    /* Test ft_strnstr */
    printf("\n\n----- Test ft_strnstr -----\n");
    test_ft_strnstr();
    
    // /* Test ft_atoi */
    // printf("\n\n----- Test ft_atoi -----\n");
    // test_ft_atoi();
}