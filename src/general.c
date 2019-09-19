/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:41:38 by jstoneha          #+#    #+#             */
/*   Updated: 2019/04/19 11:36:15 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_game	game_init(void)
{
	t_game	s;

	s.map = NULL;
	s.line = NULL;
	s.x_len = 0;
	s.y_len = 0;
	s.o.x = 0;
	s.o.y = 0;
	s.x.x = 0;
	s.x.y = 0;
	s.piece.piece = NULL;
	s.piece.x_len = 0;
	s.piece.y_len = 0;
	s.insert_crd.heat = 9999;
	s.insert_crd.y = 0;
	s.insert_crd.x = 0;
	s.hm.heat_map = NULL;
	s.hm.x = 0;
	s.hm.y = 0;
	return (s);
}

void	clear_struct(t_game *game)
{
	game->map = NULL;
	game->line = NULL;
	game->x_len = 0;
	game->y_len = 0;
	game->o.x = 0;
	game->o.y = 0;
	game->x.x = 0;
	game->x.y = 0;
	game->piece.piece = NULL;
	game->piece.x_len = 0;
	game->piece.y_len = 0;
	game->hm.heat_map = NULL;
	game->hm.x = 0;
	game->hm.y = 0;
	game->insert_crd.heat = 9999;
	game->insert_crd.y = 0;
	game->insert_crd.x = 0;
}

void	create_direction(t_game *game)
{
	game->insert_dir[0][0] = -1;
	game->insert_dir[0][1] = 0;
	game->insert_dir[1][0] = -1;
	game->insert_dir[1][1] = 1;
	game->insert_dir[2][0] = 0;
	game->insert_dir[2][1] = 1;
	game->insert_dir[3][0] = 1;
	game->insert_dir[3][1] = 1;
	game->insert_dir[4][0] = 1;
	game->insert_dir[4][1] = 0;
	game->insert_dir[5][0] = 1;
	game->insert_dir[5][1] = -1;
	game->insert_dir[6][0] = 0;
	game->insert_dir[6][1] = -1;
	game->insert_dir[7][0] = -1;
	game->insert_dir[7][1] = -1;
}

int		check_dir(t_game *game, int i)
{
	if (((game->hm.x + game->insert_dir[i][0]) < game->y_len &&
		(game->hm.y + game->insert_dir[i][1]) < game->x_len) &&
		((game->hm.x + game->insert_dir[i][0]) >= 0 &&
		(game->hm.y + game->insert_dir[i][1]) >= 0) &&
		game->hm.heat_map[game->hm.x + game->insert_dir[i][0]]
		[game->hm.y + game->insert_dir[i][1]] == 0)
		return (1);
	return (0);
}

void	give_crd(t_game *game)
{
	clear_n_free(game);
	ft_putnbr(game->insert_crd.y);
	ft_putchar(' ');
	ft_putnbr(game->insert_crd.x);
	ft_putchar('\n');
	clear_struct(game);
}
