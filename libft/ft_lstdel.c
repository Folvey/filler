/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:41:41 by jstoneha          #+#    #+#             */
/*   Updated: 2018/12/17 02:05:43 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*listik;
	t_list	*nextlist;

	listik = *alst;
	if (!alst || !del)
		return ;
	while (listik)
	{
		nextlist = listik->next;
		del(listik->content, listik->content_size);
		free(listik);
		listik = nextlist;
	}
	*alst = NULL;
}
