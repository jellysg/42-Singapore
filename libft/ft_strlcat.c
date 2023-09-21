/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:26:06 by jergoh            #+#    #+#             */
/*   Updated: 2023/09/21 10:26:08 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	cat;
	size_t	result;

	if (size == 0)
		return (ft_strlen(src));
	else if (size < ft_strlen(dest))
		result = ft_strlen(src) + size;
	else
		result = ft_strlen(src) + ft_strlen(dest);
	count = 0;
	while (dest[count] != '\0')
		count++;
	cat = 0;
	while (src[cat] != '\0' && count + 1 < size)
	{
		dest[count] = src[cat];
		cat++;
		count++;
	}
	dest[count] = '\0';
	return (result);
}
