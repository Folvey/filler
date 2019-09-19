/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:00:05 by jstoneha          #+#    #+#             */
/*   Updated: 2019/04/18 20:00:06 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	piece_cpy(t_game *game)
{
	int	y;
	int	j;

	y = 0;
	j = 0;
	game->piece.piece = malloc(sizeof(char *) * game->piece.y_len);
	while (y < game->piece.y_len)
	{
		get_next_line(0, &(game)->line);
		game->piece.piece[y] = ft_strdup(game->line);
		y++;
	}
}

void	piece(t_game *game)
{
	get_next_line(0, &(game)->line);
	game->piece.y_len = ft_atoi(ft_strchr(game->line, ' '));
	game->piece.x_len = ft_atoi(ft_strrchr(game->line, ' '));
	piece_cpy(game);
}
