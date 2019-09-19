/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:19:27 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/13 15:05:41 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mmr;
	size_t	i;

	i = 0;
	mmr = malloc(size);
	if (mmr == NULL)
		return (0);
	while (i < size)
		mmr[i++] = 0;
	return (mmr);
}
