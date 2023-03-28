#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

typedef struct zone {
	int 	wid;
	int 	hei;
	char 	*mat;
}	zone;

typedef struct circle {
	char	type;
	float	x;
	float	y;
	float	rad;
	char	c;
}	circle;

int		get_info(FILE *file, zone *z) {
	char	*cir;
	char	back;

	if (fscanf(file, "%d %d %c\n", &z->wid, &z->hei, &back) == 3) {
		if (z->wid < 1 || z->wid > 300 || z->hei < 1 || z->hei > 300)
			return 1;
		if (!(cir = (char *) malloc(z->wid * z->hei)))
			return 1;
		z->mat = cir;
		for (int i=0; i<z->wid*z->hei; i++)
			z->mat[i] = back;
		return 0;
	}
	return 1;
}

float	sq_dist(float x1, float y1, float x2, float y2) {
	return ((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

int		is_in_circle(circle *c, float x, float y) {
	float dist_sqrt = sqrtf(sq_dist(x, y, c->x, c->y));
	float dist = dist_sqrt - c->rad;
	if (dist <= -1.00000000)
		return 1;
	if (dist <= 0.00000000)
		return 2;
	return 0;
}

void	execute_one(circle *c, zone *z, int x, int y) {
	int is_in = is_in_circle(c, (float)x, (float)y);
	if (is_in == 2 || is_in == 1 && c->type == 'C')
		z->mat[x + y * z->wid] = c->c;
}

int		apply_op(circle *c, zone *z) {
	if (c->rad <= 0.00000000 || (c->type != 'C' && c->type != 'c'))
		return 1;
	for (int i=0; i<z->wid; i++) {
		for (int j=0; j<z->hei; j++)
			execute_one(c, z, i, j);
	}
	return 0;
}

void	print_circle(zone *z) {
	for (int i=1; i<=z->hei * z->wid; i++) {
		write(1, &(z->mat[i-1]), 1);
		if (i % z->wid == 0)
			write(1, "\n", 1);
	}
}

int		execute(FILE *file) {
	zone	z;
	circle	c;
	int		i, err = 0;

	if (!err && !get_info(file, &z)) {
		while (!err && (i = fscanf(file, "%c %f %f %f %c\n", &c.type, &c.x, &c.y, &c.rad, &c.c)) == 5) {
			if (apply_op(&c, &z))
				err = 1;
		}
		if (i == -1)
			print_circle(&z);
		else
			err = 1;
	}
	return err;
}

int		main(int ac, char **av) {
	FILE	*file;

	if (ac == 2) {
		file = fopen(av[1], "r");
		if (file && !execute(file))
			return 0;
		write(1, "Error: Operation file corrupted\n", 32);
	}
	else {
		write(1, "Error: argument\n", 16);
	}
	return 1;
}