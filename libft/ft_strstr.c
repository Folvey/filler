/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:44:22 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/14 20:03:37 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_does_occur(const char *str1,
const char *str2, size_t i, size_t j)
{
	while (str1[i] == str2[j])
	{
		if (str2[j + 1] == '\0')
			return (1);
		i++;
		j++;
	}
	return (0);
}

char		*ft_strstr(const char *str1, const char *str2)
{
	size_t	i;
	size_t	j;
	size_t	rmb;

	i = 0;
	j = 0;
	if (str1[i] == str2[j] && str1[i] == '\0')
		return ((char *)str1);
	if (!str2[j])
		return ((char *)str1);
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[j])
		{
			rmb = i;
			if (ft_does_occur(str1, str2, i, j) == 1)
				return ((char *)str1 + (i - j));
			j = 0;
			i = rmb;
		}
		i++;
	}
	return (NULL);
}
