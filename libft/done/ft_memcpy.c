#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	const char	*s_buffer;
	char	*d_buffer;

	i = 0;
	s_buffer = (char *)src;
	d_buffer = (char *)dest;
	while (i < n && (src || dest))
	{
		d_buffer[i] = s_buffer[i];
		i++;
	}
	return (dest);
}

#include <stdio.h>

int main ()
{
   char dest[20] = "destination";
   const char src[20]  = "source";

   printf("Before memcpy dest = %s, src = %s\n", dest, src);
   ft_memcpy(dest, src, 9);
   printf("After memcpy dest = %s, src = %s\n", dest, src);

   return(0);
}
