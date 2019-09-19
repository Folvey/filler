/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:12:35 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/15 14:54:47 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < (int)n - 1)
		i++;
	if (n)
		return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
	return (0);
}
