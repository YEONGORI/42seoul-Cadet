#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct z {
	int		wid;
	int		hei;
	char	*mat;
} zone;

typedef struct r {
	char	type;
	float	x;
	float	y;
	float	wid;
	float	hei;
	char	c;
}	rect;

int		get_info(FILE *file, zone *z) {
	char	back;
	char	*tmp;

	if (fscanf(file, "%d %d %c\n", &z->wid, &z->hei, &back) == 6) {
		if (z->wid < 1 || z->wid > 300 || z->hei < 1 || z->hei > 300)
			return 1;
		if (!(tmp = (char *) malloc(z->wid * z->hei)))
			return 1;
		z->mat = tmp;
		for (int i=0; i < z->wid * z->hei; i++)
			z->mat[i] = back;
	}
	return 1;
}

void	print_rect(zone *z) {
	for (int i=1; i<=z->hei*z->wid; i++) {
		write(1, &z->mat[i-1], 1);
		if (i % z->wid == 0)
			write(1, "\n", 1);
	}
}

int		is_in_rect(rect *r, float x, float y) {
	if (x < r->x || y < r->y || r->x + r->wid < x || r->y + r->hei < y)
		return 0;
	if (x - r->x < 1.00000000 || y - r->y < 1.00000000 ||
		r->x + r->wid - x < 1.00000000 || r->y + r->hei - y < 1.00000000)
		return 2;
	return 1;
}

void	operation_one(zone *z, rect *r, int x, int y) {
	int	is_in = is_in_rect(r, (float)x, (float)y);
	if (is_in == 2 || (is_in == 1 && r->type == 'C'))
		z->mat[x + y * z->wid] = r->c;
}

int		operation(zone *z, rect *r) {
	if (z->wid <= 0.00000000 || z->hei <= 0.00000000 || (r->type != 'C' && r->type != 'c'))
		return 1;
	for (int i=0; i<z->wid; i++) {
		for (int j=0; j<z->hei; j++) {
			operation_one(z, r, i, j);
		}
	}
	return 0;
}

int		execute(FILE *file) {
	zone	z;
	rect	r;
	int		i, err = 0;
	if (!err && !get_info(file, &z)) {
		while (!err && (i = fscanf(file, "%c %f %f %f %f %c\n", &r.type, &r.x, &r.y, &r.wid, &r.hei, &r.c)) == 6) {
			if (operation(&z, &r))
				err = 1;
		}
		if (i != -1)
			err = 1;
		else
			print_rect(&z);
	}
	return 1;
}

int 	main(int ac, char **av) {
	FILE *file;
	if (ac == 2) {
		if (!(file = fopen(av[1], "r")))
			write(1, "Error: Operation file corrupted\n", 32);
		else if (execute(file)) {
			write(1, "Error: Operation file corrupted\n", 32);
			fclose(file);
		}
		fclose(file);
		return 0;
	}
	else
		write(1, "Error: argument\n", 16);
	return 1;
}