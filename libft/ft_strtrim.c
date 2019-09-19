/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:57:12 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/15 14:42:24 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		if (s[i] == '\0')
			return (NULL);
		len--;
	}
	len < 0 ? len = 0 : len;
	if (!(str = malloc(len + 2)))
		return (NULL);
	while (j <= len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
