/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:24:31 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/12 09:11:52 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TS 32

# define WIN_WIDTH 1248
# define WIN_HEIGHT 512

# include "../MLX42/include/MLX42/MLX42.h"
# include "../inc/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

typedef struct txt_inf
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
}					t_texture_info;

typedef struct movement
{
	int				nb_move;
}					t_movement;

typedef struct lmp
{
	char			**mapp;
	int				max_x;
	size_t			nb_c;
	int				nb_l;
	int				nb_e;
	int				nb_p;
	int				nb_enemy;
	int				nb_other;
}					t_lamap;

typedef struct all
{
	t_movement		move;
	t_lamap			mapy;
	t_texture_info	textinf[15];
	mlx_t			*mlx;
}					t_all;

void				ft_hook(void *param);
int					main(int ac, char **av);
void				count_line(t_all *all, char *argv);
int					is_pos_valid(int x, int y, t_all *all);
void				aff_map(int fd, t_all *all);
void				collectible(t_all *all);
int					notladder(int x, int y, t_all *all);
void				mouv_barrel(t_all *all);
void				mouv_down(t_all *all);
void				mouv_left(t_all *all);
void				mouv_right(t_all *all);
void				is_map_valid(t_all *all);
void				animate_next_frame(void *param);
void				aff_back(int y, t_all *all);
void				conditions(t_all *all, int newX, int newY);
void				movements(t_all *all, int *newX, int *newY);
void				error(int ac, t_all *all);
void				display_number(t_all *all, int nb_move, int32_t x,
						int32_t y);
void				move(t_all *all, int *newX, int *newY);
bool				flood(t_all *all, int x, int y);
void				free_tab(char **tab);
void				closemap(t_all *all);
void				isok(t_all *all);
void				finish(t_all *all);
void				isrectangular(t_all *all);

#endif