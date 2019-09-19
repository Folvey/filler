/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:15:38 by jstoneha          #+#    #+#             */
/*   Updated: 2019/04/19 11:40:22 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_insert_crd
{
	int				heat;
	int				x;
	int				y;
}					t_insert_crd;

typedef struct		s_heat_map
{
	int				**heat_map;
	int				x;
	int				y;
}					t_heat_map;

typedef struct		s_piece
{
	char			**piece;
	int				x_len;
	int				y_len;
}					t_piece;

typedef	struct		s_o
{
	int				x;
	int				y;
}					t_o;

typedef	struct		s_x
{
	int				x;
	int				y;
}					t_x;

typedef struct		s_game
{
	t_piece			piece;
	t_x				x;
	t_o				o;
	t_heat_map		hm;
	t_insert_crd	insert_crd;
	int				insert_dir[8][2];
	char			**map;
	char			*line;
	char			me;
	char			enemy;
	int				x_len;
	int				y_len;
}					t_game;

void				play(t_game *game);
void				player(t_game *game);
void				map(t_game *game);
void				create_heat_map(t_game *game);
void				insert_piece(t_game *game);
void				clear_n_free(t_game *game);

/*
**-------------- general ----------------**
*/
t_game				game_init(void);
void				clear_struct(t_game *game);
void				create_direction(t_game *game);
int					check_dir(t_game *game, int i);
void				give_crd(t_game *game);
#endif
