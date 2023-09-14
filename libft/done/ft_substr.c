/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:41:10 by jergoh            #+#    #+#             */
/*   Updated: 2023/09/14 14:41:11 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	counter;
	char	*result;

	counter = 0;
	if (!s || !len)
		result = malloc(1 * sizeof(char));
	else
	{
		result = malloc((len + 1) * sizeof(char));
		if (result == NULL)
			return (NULL);
		while (counter < len && s[counter])
		{
			result[counter] = s[start];
			start++;
			counter++;
		}
	}
	result[counter] = '\0';
	return (result);
}

#include <stdio.h>

int	main (void)
{
	const char *s = "This is a sample string";
	unsigned int start = 2;
	size_t len = 10;

	printf("String: %s\nStart at position: %d\nLength :%zu\n", s, start, len);
	printf("Substring: %s\n", ft_substr(s, start, len));
}
