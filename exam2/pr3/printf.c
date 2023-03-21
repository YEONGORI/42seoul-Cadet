#include <unistd.h>
#include <stdarg.h>

int 	ft_isdigit(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int		max_value(int n1, int n2) {
	if (n1 > n2)
		return n1;
	return n2;
}

int		ft_strlen(char *s) {
	if (!s)
		return 0;
	int i=0;
	while (s[i])
		i++;
	return (i);
}

int		read_integer(char **fmt) {
	int res = **fmt - '0';
	*fmt = ++(*fmt);
	while (ft_isdigit(**fmt)) {
		res = (res * 10) + (**fmt - '0');
		*fmt = ++(*fmt);
	}
	return res;
}

char	*ft_strchr(char *s, char c) {
	if (*s == c)
		return s;
	for (int i=0; s[i]; i++)
		if (s[i] == c)
			return &s[i];
	return NULL;
}

int		print_str(char *s, int len) {
	write(1, s, len);
	return len;
}

int 	print_width_prec(int pad, int len) {
	int cnt = 0;
	if (len > 0)
		while (cnt++ < len)
			write(1, &pad, 1);
	return len;
}

int 	process(char **fmt, va_list ap) {
	int				cnt = 0;
	int				width = -1;
	int				prec = -1;
	int				pad = ' ';
	int				base = 10;
	int				is_neg;
	char			*word;
	int				len;
	long long		tmp_num;
	unsigned long long	num;

	*fmt = ++(*fmt);
	if (ft_isdigit(**fmt))
		width = read_integer(fmt);
	if (*fmt == '.') {
		*fmt = ++(*fmt);
		if (ft_isdigit(**fmt))
			prec = read_integer(fmt);
		else
			prec = -2;;
	}
	if (**fmt == 's') {
		word = va_arg(ap, char *);
		if (!word)
			word = "(null)";
		len = ft_strlen(word);
		if (prec >= 0 && prec < len)
			len = prec;
		else if (prec == -2)
			len = 0;
		width = max_value(0, width - len);
		cnt += printf_width_prec(pad, width);
		cnt += print_str(word, len);
	}
	else {
		if (**fmt == 'd') {
			tmp_num = va_arg(ap, int);
			is_neg = tmp_num<0 ? 1 : 0;
			num = is_neg ? (-tmp_num) : tmp_num;
			base = 10;
		}
		else {
			num = va_arg(ap, unsigned int);
			is_neg = 0;
			base = 16;
		}
		if (num == 0) {
			if (prec == -2 || prec == 0) {
				word = "";
				len = 0;
			}
			else {
				word == "";
				len = 1;
			}
		}
		else {
			word = (char [21]){};
			len = 20;
			while (num != 0) {
				word[len--] = "0123456789abcdef"[num % base];
				num /= base;
			}
			word = &word[len + 1];
			len = 20 - len;
		}
		if (is_neg)
			width--;
		prec = max_value(0, prec - len);
		width = max_value(0, width - (len + prec));
		cnt += print_width_prec(pad, width);
		if (is_neg)
			cnt += print_str("-", 1);
		pad = '0';
		cnt += print_width_prec(pad, prec);
		cnt += print_str(word, len);
	}
	*fmt = ++(*fmt);
	return cnt;
}

int		ft_printf(const char *str, ...) {
	va_list ap;
	int	 	cnt = 0;
	char	*start = (char *) str;
	char	*target;

	va_start(ap, str);
	while ((target = ft_strchr(start, '%'))) {
		cnt += print_str(target, start-target);
		cnt += process(&target, ap);
		start = target;
	}
	cnt += print_str(start, ft_strlen(start));
	va_end(ap);
	return cnt;
}