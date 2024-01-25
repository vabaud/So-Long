/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:24:31 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/25 21:50:16 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 32

#define WIN_WIDTH 1248
#define WIN_HEIGHT 512

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include <stdbool.h>
#include <sys/time.h>

typedef struct txt_inf{
    mlx_texture_t* texture;
    mlx_image_t* img;
} TextureInfo;

typedef struct {
    int gravity;
    unsigned long long vit;
} movement;

typedef struct lmp {
    char** mapp;
    int maxY;
    int maxX;
    size_t nb_c;
    int nb_l;
} lamap;

typedef struct {
    movement move; 
    lamap mapy;
    TextureInfo textInf[15];
    mlx_t* mlx;
} t_all;



void	ft_hook(void* param); 
int		main(int ac, char **av);
void	count_line(t_all *all, char *argv);
int		isPositionValid(int x, int y, t_all *all);
void	aff_map(int fd, t_all *all);
void	collectible(t_all *all);
//bool	jump(int x, int y, t_all *all);
int		notladder(int x, int y, t_all *all);
void	mouvBarrel(t_all *all);
void	mouv_down(t_all *all);
void	mouv_left(t_all *all);
void	mouv_right(t_all *all);
unsigned long long	getCurrentTimeInMilliseconds(void);
void	isMapValid(t_all *all);
void	animate_next_frame(void *param);
void	aff_back(int y, t_all *all);

#endif