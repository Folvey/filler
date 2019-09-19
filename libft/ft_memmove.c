/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:23:35 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/17 02:15:25 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	if (dest == source)
		return (NULL);
	if (dest < source)
		while (i < len)
		{
			*(dest + i) = *(source + i);
			i++;
		}
	else
		while ((long long)--len >= 0)
			*(dest + len) = *(source + len);
	return (dst);
}
