#include <unistd.h>
#include <stdarg.h>

#define BUF 16
#define PAD 16

const char	*digits = "0123456789abcdef";
const char	*zero = "0000000000000000";
const char	*space = "                ";

typedef struct s_data {
	char			*fmt, *ptr;
	char			c, sign;
	int				ret, zeroflag;
	int				width, prec;
	int				len, reallne, prelen;
	unsigned int	val;
	char			buf[BUF];
} t_data;

int is_digit(char c) {
	return ('0' <= c && c <= '9');
}

void itoa_base(t_data *d, int base) {
	if (d->prec >= 0)
		d->zeroflag = 0;
	d->ptr = d->buf + BUF;
	if (d->val || d->prec) {
		*(--d->ptr) = digits(d->val % base);
		d->val /= base;
		while (d->val) {
			*(--d->ptr) = digits[d->val % base];
			d->val /= base;
		}
	}
	d->len = d->buf + BUF - d->ptr;
}

int get_flag(t_data *d, va_list ap) {
	while (1) {
		d->c = *d->fmt++;
		if (d->c == 0)
			return (0);
		else if (d->c == '.') {
			d->prec = 0;
			d->c = *d->fmt++;
			while (is_digit(d->c)) {
				d->width = (10 * d->width) + (d->c - '0');
				d->c = *d->fmt++;
			}
			d->fmt--;
		}
		else if (is_digit(d->c)) {
			if (d->c == '0')
				d->zeroflag = 1;
			else {
				d->width = d->c - '0';
				d->c = *d->fmt++;
				while (is_digit(d->c)) {
					d->width = (10 * d->width) + (d->c - '0');
					d->c = *d->fmt++;
				}
				d->fmt--;				
			}
		}
		else if (d->c == 'd') {
			d->val = va_arg(ap, int);
			if ((int)d->val < 0) {
				d->val *= -1;
				d->sign = '-';
			}
			itoa_base(d, 10);
			return (1);
		}
	}
}


int ft_printf(const char *fmt, ...) {
	va_list ap;
	t_data d = {0};

	d.fmt = (char *)fmt;
	va_start(ap, fmt);
	while (1) {
		d.ptr = d.fmt;
		while ((d.c = *d.fmt) && d.c != '%')
			d.fmt++;
		write(1, d.ptr, d.fmt - d.ptr);
		d.ret += d.fmt - d.ptr;
		if (d.c == 0)
			break ;
		d.fmt++;
		d.width = d.zeroflag = d.sign = 0;
		d.prec = -1;
		if (!get_flag(&d, ap))
			break;
		put_after_percent(&d);
	}
	va_end(ap);
	return (d.ret);
}