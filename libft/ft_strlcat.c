/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:35:45 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/14 21:52:42 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(dest);
	if (len + 1 > size)
		return (ft_strlen(src) + size);
	while (src[j] && ((len + j) < size - 1))
	{
		dest[len + j] = src[j];
		j++;
	}
	dest[len + j] = '\0';
	return (len + ft_strlen(src));
}
