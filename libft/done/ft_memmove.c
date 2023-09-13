#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char	*d_buffer;
	char	*s_buffer;

	i = n;
	d_buffer = (char *)dest;
	s_buffer = (char *)src;
	if (dest == src)
		return (dest);
	else if (d_buffer > s_buffer)
	{
		while (i > 0)
			*(d_buffer + i) = *(s_buffer + i);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(d_buffer + i) = *(s_buffer + i);
			i++;
		}
	}
	return (d_buffer);
}

#include <stdio.h>

int main ()
{
   char dest[20] = "destination";
   const char src[20]  = "source";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   ft_memmove(dest, src, 9);
   printf("After memmove dest = %s, src = %s\n", dest, src);

   return(0);
}
