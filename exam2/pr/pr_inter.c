#include <unistd.h>

int main(int ac, char **av)
{
	int flag[128] = {0};
	int i;

	if (ac == 3) {
		for (i = 0; av[2][i]; i++)
			flag[(unsigned char)av[2][i]] = 1;
		for (i = 0; av[1][i]; i++) {
			if (flag[(unsigned char)av[1][i]] == 1) {
				write(1, &av[1][i], 1);
				flag[(unsigned char)av[1][i]] = 0;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}