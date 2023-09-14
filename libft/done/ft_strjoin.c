#include "libft.h"

static char	*ft_strcat(char const *s1, char const *s2, char *res)
{
	unsigned int	count;
	unsigned int	total;

	count = 0;
	total = 0;
	while (s1[count] != '\0')
	{
		res[total] = s1[count];
		count++;
		total++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		res[total] = s2[count];
		count++;
		total++;
	}
	res[total] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res = ft_strcat(s1, s2, res);
	return (res);
}
