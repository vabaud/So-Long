/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:24:31 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/11 17:10:35 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 16

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include <stdbool.h>

typedef struct txt_inf{
    mlx_texture_t* texture;
    mlx_image_t* img;
} TextureInfo;

typedef struct lmp{
    char** mapp;
} lamap;

extern lamap mapy;
extern TextureInfo textureInfoArray[13];

void ft_hook(void* param);
int main(void);
int isPositionValid(int x, int y);
void aff_map(int fd, mlx_t *mlx);
// void draw_image(app_t *app);

#endif