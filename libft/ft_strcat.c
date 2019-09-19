/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:50:21 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/16 18:59:18 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t wtcp;

	i = 0;
	wtcp = ft_strlen(s1);
	while (i < ft_strlen((char*)s2))
	{
		s1[wtcp] = s2[i];
		i++;
		wtcp++;
	}
	s1[wtcp] = '\0';
	return (s1);
}
