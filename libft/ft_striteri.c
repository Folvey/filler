/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:11:15 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/17 01:12:12 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	first_argument;
	size_t			i;

	i = 0;
	first_argument = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f(first_argument, &s[i]);
		i++;
		first_argument++;
	}
}
