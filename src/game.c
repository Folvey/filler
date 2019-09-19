/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:58:26 by jstoneha          #+#    #+#             */
/*   Updated: 2019/04/19 11:34:57 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	play(t_game *game)
{
	int i;

	i = 0;
	get_next_line(0, &((game)->line));
	player(game);
	map(game);
	create_heat_map(game);
	insert_piece(game);
}
