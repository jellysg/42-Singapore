#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_putaddress(void *addr);
size_t	ft_putchar(const char c);
size_t	ft_puthex_l(const unsigned int hex);
size_t	ft_puthex_u(const unsigned int hex);
size_t	ft_putnbr(const int n);
size_t	ft_putstr(const char *str);
size_t	ft_putunbr(const unsigned int un);

#endif
