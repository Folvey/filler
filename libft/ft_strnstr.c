/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:33:05 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/15 17:25:33 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_does_occur(const char *str1, const char *str2,
size_t i, size_t j)
{
	while (str1[i] == str2[j])
	{
		if (str2[j + 1] == '\0')
			return (i);
		i++;
		j++;
	}
	return (0);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	rmb;
	size_t	j;

	j = 0;
	i = 0;
	if (s1 == s2)
		return ((char *)s1);
	if (s2[j] == '\0')
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		if (s1[i] == s2[j])
		{
			rmb = i;
			if (ft_does_occur(s1, s2, i, j) != 0
			&& ft_does_occur(s1, s2, i, j) < len)
				return ((char *)s1 + rmb);
			i = rmb;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
