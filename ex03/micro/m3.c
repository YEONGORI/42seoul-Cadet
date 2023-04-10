#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct z {
	int wid;
	int hei;
	char *mat;
}	zone;

typedef struct r {
	char type;
	float x;
	float y;
	float wid;
	float hei;
	char c;
}	rect;

int	get_info(FILE *file, zone *z) {
	char	*mat;
	char	back;

	if (fscanf(file, "%d %d %c\n", &z->wid, &z->hei, &back) == 3) {
		if (z->wid < 1 || z->wid > 300 || z->hei < 1 || z->hei > 300)
			return 1;
		if (!(mat = (char *) malloc(z->wid * z->hei)))
			return 1;
		z->mat = mat;
		for (int i=0; i < z->hei * z->wid; i++)
			z->mat[i] = back;
		return 0;
	}
	return 1;
}

void print_rect(zone *z) {
	for (int i=1; i<=z->wid*z->hei; i++) {
		write(1, &z->mat[i-1], 1);
		if (i % z->wid == 0)
			write(1, "\n", 1);
	}
}

int	is_in_rect(rect *r, float x, float y) {
	if (x < r->x || y < r->y || r->x + r->wid < x || r->y + r->hei < y)
		return 0;
	if (x - r->x < 1.00000000 || (r->x + r->wid) - x < 1.00000000 ||
		y - r->y < 1.00000000 || (r->y + r->hei) - y < 1.00000000)
		return 2;
	return 1;
}

void operation_one(zone *z, rect *r, int x, int y) {
	printf("%f %f %f %f\n", r->x, r->y, r->wid, r->hei);
	int is_in = is_in_rect(r, (float)x, (float)y);
	if (is_in == 2 || (is_in == 1 && r->type == 'R')) {
		z->mat[x + y*z->wid] = r->c;
		printf("%c\n", r->c);
	}
}

int	operation(zone *z, rect *r) {
	if (r->wid <= 0.00000000 || r->hei <= 0.00000000 || (r->type != 'R' && r->type != 'r'))
		return 1;
	for (int i=0; i<r->wid; i++) {
		for (int j=0; j<r->hei; j++) {
			operation_one(z, r, i, j);
			printf("HIHI");
		}
	}
	return 0;
}

int	execute(FILE *file) {
	zone	z;
	rect	r;
	int		i, err = 0;

	if (!err && !get_info(file, &z)) {
		while (!err && (i = fscanf(file, "%c %f %f %f %f %c\n", &r.type, &r.x, &r.y, &r.wid, &r.hei, &r.c)) == 6) {
			if (operation(&z, &r))
				err = 1;
			printf("QQ\n");
		}
		if (i == -1)
			print_rect(&z);
		else
			err = 1;
	}
	fclose(file);
	return err;
}

int main(int ac, char **av) {
	FILE	*file;

	if (ac == 2) {
		file = fopen(av[1], "r");
		if (!file)
			write(1, "ERROR\n", 6);
		if (execute(file))
			write(1, "ERROR\n", 6);
		return 0;
	}
	return 1;
}