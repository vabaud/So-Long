/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:24:31 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/12 15:58:18 by vabaud           ###   ########.fr       */
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

typedef struct {
    float x, y;
    mlx_texture_t *texture;
} Character;

static Character character;

void ft_hook(void* param);
int main(void);
// void draw_image(app_t *app);

#endif