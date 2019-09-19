/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:15:03 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/17 01:29:35 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strings(char const *s, char c)
{
	size_t	i;
	size_t	string;

	i = 0;
	string = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			string++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (string);
}

static char		**ft_free(char **otec_massivov, size_t nomerok)
{
	while (nomerok--)
		free(otec_massivov[nomerok]);
	free(otec_massivov);
	otec_massivov = NULL;
	return (otec_massivov);
}

static char		**ft_rabotnik(char const *s, char c, char **otec_massivov)
{
	size_t	i;
	size_t	len;
	size_t	nomerok;

	nomerok = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = 0;
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		if (nomerok < (count_strings(s, c)))
			if (!(otec_massivov[nomerok++] = ft_strsub(s, i - len, len)))
				ft_free(otec_massivov, nomerok);
	}
	otec_massivov[nomerok] = NULL;
	return (otec_massivov);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**otec_massivov;

	if (!s || !(otec_massivov = (char **)malloc(sizeof(char *)
	* (count_strings(s, c)) + 1)))
		return (NULL);
	ft_rabotnik(s, c, otec_massivov);
	return (otec_massivov);
}
