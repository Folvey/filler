/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:20:38 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/13 14:25:20 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = -1;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (++i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == (unsigned char)c)
		{
			s1[i] = (unsigned char)c;
			ptr = s1 + (i + 1);
			return (ptr);
		}
	}
	return (NULL);
}
