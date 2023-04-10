#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct zone {
	int			wid;
	int			hei;
	char		*matric;
}	zone;

typedef struct rect {
	char		r;
	float		x;
	float		y;
	float 		wid;
	float 		hei;
	char		c;
}	rect;

int		ft_strlen(char *s) {
	if (!s)
		return 0;
	int i=0;
	while (s[i])
		i++;
	return i;
}

int		get_info(FILE *file, zone *z) {
	char	*mat;
	char	back;

	if (fscanf(file, "%d %d %c\n", &z->wid, &z->hei, &back) == 3) {
		if (z->wid < 1 || z->wid > 300 || z->hei < 1 || z->hei > 300)
			return 1;
		if (!(mat = (char *) malloc(z->wid * z->hei)))
			return 1;
		z->matric = mat;
		for (int i=0; i < z->hei * z->wid; i++)
			z->matric[i] = back;
		return 0;
	}
	return 1;
}

int		is_in_rect(rect *r, float x, float y) {
	if (x < r->x || y < r->y || r->x + r->wid < x || r->y + r->hei < y)
		return 0;
	if (x - r->x < 1.00000000 || (r->x + r->wid) - x < 1.00000000 ||
		y - r->y < 1.00000000 || (r->y + r->hei) - y < 1.00000000)
		return 2;
	return 1;
}

void 	execute_one(rect *r, zone *z, int x, int y) {
	printf("%f %f %f %f\n", r->x, r->y, r->wid, r->hei);
	int is_in = is_in_rect(r, (float)x, (float)y);
	if (is_in == 2 || (is_in == 1 && r->r == 'R')) {
		z->matric[x + y*z->wid] = r->c;
		printf("%c\n", r->c);
	}
}

int 	apply_op(rect *r, zone *z) {
	if (r->wid <= 0.00000000 || r->hei <= 0.00000000 || (r->r != 'R' && r->r != 'r'))
		return 1;
	for (int i=0; i<z->wid; i++) {
		for (int j=0; j<z->hei; j++) {
			execute_one(r, z, i, j);
			printf("HIHI");
		}
	}
	return 0;
}

void	print_rect(zone *z) {
	char	c;
	for (int i = 1; i <= z->hei * z->wid; i++) {
		char c = z->matric[i-1];
		write(1, &c, 1);
		if (i % z->wid == 0)
			write(1, "\n", 1);
	}
}

int		execute(FILE *file) {
	zone	z;
	rect	r;
	int		i, err = 0;

	if (!err && !get_info(file, &z)) {
		while (!err && (i = fscanf(file, "%c %f %f %f %f %c\n", &r.r, &r.x, &r.y, &r.wid, &r.hei, &r.c)) == 6) {
			printf("QQ\n");
			if (apply_op(&r, &z))
				err = 1;
		}
		if (i == -1)
			print_rect(&z);
		else
			err = 1;
	}
	fclose(file);
	return err;
}

int 	main(int ac, char **av) {
	FILE	*file;

	if (ac == 2) {
		file = fopen(av[1], "r");
		if (file && !execute(file))
			return 0;
		write(1, "Error: Operation file corrupted\n", ft_strlen("Error: Operation file corrupted\n"));
	}
	else
		write(1, "Error: argument\n", ft_strlen("Error: argument\n"));
	return 1;	
}