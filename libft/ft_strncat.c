/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:46:33 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/06 17:04:49 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t wtcp;

	i = 0;
	wtcp = ft_strlen(s1);
	while ((i < len) && s2[i] != '\0')
	{
		s1[wtcp] = s2[i];
		wtcp++;
		i++;
	}
	s1[wtcp] = '\0';
	return (s1);
}
