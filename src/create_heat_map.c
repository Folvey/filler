/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:07:34 by jstoneha          #+#    #+#             */
/*   Updated: 2019/04/19 11:51:57 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	test_heat(t_game *game)
{
	game->hm.x = 0;
	while (game->hm.x < game->y_len)
	{
		game->hm.y = 0;
		while (game->hm.y < game->x_len)
			game->hm.y++;
		game->hm.x++;
	}
}

int		insert_hot(t_game *game, int find)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	if (find == 0)
		game->hm.heat_map[game->hm.x][game->hm.y] = 999;
	while (i < 8)
	{
		if (check_dir(game, i))
		{
			if (find == 0)
				game->hm.heat_map[game->hm.x + game->insert_dir[i][0]]
				[game->hm.y + game->insert_dir[i][1]] = 999;
			else
				game->hm.heat_map[game->hm.x + game->insert_dir[i][0]]
				[game->hm.y + game->insert_dir[i][1]] = (find == -2)
				? 1 : find + 1;
			check++;
		}
		i++;
	}
	return (check);
}

void	fh_norm(t_game *game, int *is_zero, int find, int *check)
{
	while (game->hm.y < game->x_len)
	{
		if (game->hm.heat_map[game->hm.x][game->hm.y] == 0)
			*is_zero = 1;
		if (game->hm.heat_map[game->hm.x][game->hm.y] == find)
			*check += insert_hot(game, find);
		game->hm.y++;
	}
}

void	fill_heat(t_game *game)
{
	int find;
	int is_zero;
	int check;

	is_zero = 1;
	create_direction(game);
	find = -2;
	while (is_zero)
	{
		check = 0;
		is_zero = 0;
		game->hm.x = 0;
		while (game->hm.x < game->y_len)
		{
			game->hm.y = 0;
			fh_norm(game, &is_zero, find, &check);
			game->hm.x++;
		}
		find++;
		if (check == 0)
			find = 0;
		if (find == -1)
			find = 1;
	}
}

void	create_heat_map(t_game *game)
{
	game->hm.x = 0;
	game->hm.heat_map = (int**)malloc(sizeof(int*)
			* (game->y_len * game->x_len));
	while (game->hm.x < game->y_len)
	{
		game->hm.heat_map[game->hm.x] = (int*)malloc(sizeof(int) * game->x_len);
		game->hm.y = 0;
		while (game->hm.y < game->x_len)
		{
			if (game->map[game->hm.x][game->hm.y] == game->me
					|| game->map[game->hm.x][game->hm.y] == game->me + 32)
				game->hm.heat_map[game->hm.x][game->hm.y] = -1;
			else if (game->map[game->hm.x][game->hm.y] == game->enemy
					|| game->map[game->hm.x][game->hm.y] == game->enemy + 32)
				game->hm.heat_map[game->hm.x][game->hm.y] = -2;
			else if (game->map[game->hm.x][game->hm.y] == '.')
				game->hm.heat_map[game->hm.x][game->hm.y] = 0;
			game->hm.y++;
		}
		game->hm.x++;
	}
	fill_heat(game);
	test_heat(game);
}
