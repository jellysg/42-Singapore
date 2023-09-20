#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	while (count >= 0)
	{
		if (str[count] == (char)c)
			return ((char *)(str + count));
		count--;
	}
	return (0);
}
