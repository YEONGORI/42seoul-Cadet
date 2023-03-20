#include <unistd.h>

int main(int ac, char **av)
{
	int flag[128] = {0};

	if (ac == 3) {
		for (int i=1; i<3; i++) {
			for (int j=0; av[i][j]; j++) {
				if (flag[(unsigned char) av[i][j]] == 0) {
					write(1, &av[i][j], 1);
					flag[(unsigned char) av[i][j]] = 1;
				}
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}