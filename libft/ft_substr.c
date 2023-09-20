#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	strlen;
	size_t	end;

	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if (start >= strlen)
	{
		new = (char *)malloc(sizeof(char));
		if (!new)
			return (0);
		*new = '\0';
		return (new);
	}
	end = 0;
	if (start < strlen)
		end = strlen - start;
	if (end > len)
		end = len;
	new = (char *)malloc(sizeof(char) * (end + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, end + 1);
	return (new);
}
