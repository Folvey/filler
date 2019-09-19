/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:55:35 by jstoneha          #+#    #+#             */
/*   Updated: 2019/04/19 11:35:54 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	player(t_game *game)
{
	if ((!ft_strncmp(game->line, "$$$ exec p1", 11)))
	{
		game->me = 'O';
		game->enemy = 'X';
		get_next_line(0, &(game)->line);
	}
	else if ((!ft_strncmp(game->line, "$$$ exec p2", 11)))
	{
		game->me = 'X';
		game->enemy = 'O';
		get_next_line(0, &(game)->line);
	}
}

void	check_map_len(t_game *game)
{
	int i;

	i = 0;
	game->y_len = ft_atoi(ft_strchr(game->line, ' '));
	game->x_len = ft_atoi(ft_strrchr(game->line, ' '));
	game->map = malloc(sizeof(char *) * game->y_len);
	get_next_line(0, &(game)->line);
}

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

void	map(t_game *game)
{
	int	y;

	y = 0;
	check_map_len(game);
	while (y < game->y_len)
	{
		get_next_line(0, &(game)->line);
		game->map[y] = ft_strdup(ft_strchr(game->line, ' ') + 1);
		y++;
	}
	piece(game);
}
