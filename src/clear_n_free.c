/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_n_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:01:07 by jstoneha          #+#    #+#             */
/*   Updated: 2019/04/18 20:01:09 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	clear_map(t_game *game)
{
	int i;

	i = 0;
	while (i < game->y_len)
		free(game->map[i++]);
	free(game->map);
}

void	clear_piece(t_game *game)
{
	int i;

	i = 0;
	while (i < game->piece.y_len)
		free(game->piece.piece[i++]);
	free(game->piece.piece);
}

void	clear_hm(t_game *game)
{
	int i;

	i = 0;
	while (i < game->hm.y)
		free(game->hm.heat_map[i++]);
	free(game->hm.heat_map);
}

void	clear_n_free(t_game *game)
{
	clear_map(game);
	clear_piece(game);
	clear_hm(game);
}
