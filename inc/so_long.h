/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:24:31 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/02 17:42:38 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TS 32

# define WIN_WIDTH 1248
# define WIN_HEIGHT 512

# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <time.h>

typedef struct txt_inf
{
	mlx_texture_t		*texture;
	mlx_image_t			*img;
}						t_texture_info;

typedef struct movement
{
	int					gravity;
	unsigned long long	vit;
	int					nb_move;
}						t_movement;

typedef struct lmp
{
	char				**mapp;
	int					max_x;
	size_t				nb_c;
	int					nb_l;
}						t_lamap;

typedef struct all
{
	t_movement			move;
	t_lamap				mapy;
	t_texture_info		textinf[15];
	mlx_t				*mlx;
}						t_all;

void					ft_hook(void *param);
int						main(int ac, char **av);
void					count_line(t_all *all, char *argv);
int						is_pos_valid(int x, int y, t_all *all);
void					aff_map(int fd, t_all *all);
void					collectible(t_all *all);
int						notladder(int x, int y, t_all *all);
void					mouv_barrel(t_all *all);
void					mouv_down(t_all *all);
void					mouv_left(t_all *all);
void					mouv_right(t_all *all);
void					is_map_valid(t_all *all);
void					animate_next_frame(void *param);
void					aff_back(int y, t_all *all);
void					conditions(t_all *all, int newX, int newY);
void					movements(t_all *all, int *newX, int *newY);

#endif