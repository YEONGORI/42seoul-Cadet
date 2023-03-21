#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putstr(char *str) {

}

int	ft_putint(long n) {
	
}

int ft_printf(const char *str, ...) {
	int count = 0;
	va_list list;
	va_start(list, str);
	while (*str) {
		if (*str == '%') {
			str++;
			if (*str == 's')
				count += ft_putstr(va_arg(list, char *));
			else if (*str == 'd')
				count += ft_putint(va_arg(list, int));
			else if  (*str == 'x')
				count += ft_putdou(va_arg(list, unsigned int));
		}
		else {
			count += write(1, str, 1);
			str++;
		}
	}
	return (count);
}