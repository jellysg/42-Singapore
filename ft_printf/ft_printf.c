#include "ft_printf.h"

static size_t	conversion(const char *c, size_t *i, va_list *argptr)
{
	*i = *i + 1;
	if (*(c + 1) == 'c')
		return (ft_putchar((char) va_arg(*argptr, int)));
	else if (*(c + 1) == 's')
		return (ft_putstr(va_arg(*argptr, const char *)));
	else if (*(c + 1) == 'p')
		return (ft_putaddress(va_arg(*argptr, void *)));
	else if (*(c + 1) == 'd' || *(c + 1) == 'i')
		return (ft_putnbr(va_arg(*argptr, int)));
	else if (*(c + 1) == 'u')
		return (ft_putunbr(va_arg(*argptr, unsigned int)));
	else if (*(c + 1) == 'x')
		return (ft_puthex_l(va_arg(*argptr, int)));
	else if (*(c + 1) == 'X')
		return (ft_puthex_u(va_arg(*argptr, int)));
	else if (*(c + 1) == '%')
		return (ft_putchar('%'));
	else if (*(c + 1) && *(c + 2))
		return (ft_putchar(*(c)) + ft_putchar(*(c + 1)));
	else
	{
		*i -= 1;
		return (-1);
	}
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		tmp;
	va_list	argptr;
	size_t	i;

	if (!str)
		return (-1);
	len = 0;
	va_start(argptr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			tmp = conversion(str + i, &i, &argptr);
		else
			tmp = ft_putchar(str[i]);
		if (tmp >= 0)
			len += tmp;
		else
			len = tmp;
		i++;
	}
	va_end(argptr);
	return (len);
}
