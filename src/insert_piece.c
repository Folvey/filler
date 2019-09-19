/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:54:40 by jstoneha          #+#    #+#             */
/*   Updated: 2019/04/19 11:37:36 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		dots_fit(t_game *game, int y, int x)
{
	if (x < 0 || y < 0)
		return (0);
	if (y + game->piece.y_len > game->y_len)
		return (0);
	if (x + game->piece.x_len > game->x_len)
		return (0);
	return (1);
}

int		stars_fit(t_game *game, int y, int x)
{
	int			i;
	int			j;
	int			overlay;

	i = 0;
	overlay = 0;
	while (i < game->piece.y_len)
	{
		j = 0;
		while (j < game->piece.x_len)
		{
			if (game->piece.piece[i][j] == '*')
			{
				if (game->map[y + i][x + j] == game->enemy
					|| game->map[y + i][x + j] == game->enemy - 32)
					return (0);
				if (game->map[y + i][x + j] == game->me
					|| game->map[y + i][x + j] == game->me - 32)
					overlay++;
			}
			j++;
		}
		i++;
	}
	return (overlay);
}

int		count_heat(t_game *game, int y, int x)
{
	int	i;
	int	j;
	int	heat;

	heat = 0;
	i = 0;
	while (i < game->piece.y_len)
	{
		j = 0;
		while (game->piece.piece[i][j])
		{
			if (game->piece.piece[i][j] == '*'
					&& game->hm.heat_map[y + i][x + j] > -1)
				heat += game->hm.heat_map[y + i][x + j];
			j++;
		}
		i++;
	}
	return (heat);
}

void	appoint_ins_crd(t_game *game)
{
	int y;
	int x;
	int heat;

	y = 0;
	heat = 0;
	while (y < game->y_len)
	{
		x = 0;
		while (x < game->x_len)
		{
			if (dots_fit(game, y, x) && stars_fit(game, y, x) == 1)
			{
				heat = count_heat(game, y, x);
				if (heat < game->insert_crd.heat)
				{
					game->insert_crd.heat = heat;
					game->insert_crd.y = y;
					game->insert_crd.x = x;
				}
			}
			x++;
		}
		y++;
	}
}

void	insert_piece(t_game *game)
{
	appoint_ins_crd(game);
	if (dots_fit(game, game->insert_crd.y, game->insert_crd.x)
	&& stars_fit(game, game->insert_crd.y, game->insert_crd.x) == 1)
	{
		give_crd(game);
		play(game);
	}
	else
	{
		game->insert_crd.y = 0;
		game->insert_crd.x = 0;
		give_crd(game);
	}
}
