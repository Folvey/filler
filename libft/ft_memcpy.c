/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:43:31 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/15 18:42:25 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	if (dst == src)
		return (dst);
	i = 0;
	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	while (i < len)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dst);
}
