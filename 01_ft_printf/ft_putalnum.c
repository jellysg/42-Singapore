#include "ft_printf.h"

size_t	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

static size_t	print_nb(long nb)
{
	if (nb / 10)
		return (print_nb(nb / 10) + print_nb(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}

size_t	ft_putnbr(const int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		return (ft_putchar('-') + print_nb(nb));
	}
	else
		return (print_nb(nb));
}

size_t	ft_putunbr(const unsigned int n)
{
	if (n / 10)
		return (ft_putunbr(n / 10) + ft_putunbr(n % 10));
	else
		return (ft_putchar(n + '0'));
}
