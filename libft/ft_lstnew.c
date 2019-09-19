/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:18:29 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/16 20:36:44 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*listik;

	if (!(listik = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		listik->content = NULL;
		listik->content_size = 0;
	}
	else
	{
		if (!(listik->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(listik->content, content, content_size);
		listik->content_size = content_size;
	}
	listik->next = NULL;
	return (listik);
}
