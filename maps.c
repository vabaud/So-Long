/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:17:09 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/14 17:59:32 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

lamap mapy;
void aff_map(int fd, mlx_t *mlx)
{
    int x;
    int y = 0;
    mapy.mapp = malloc(100 * sizeof(char *));
    while ((mapy.mapp[y] = get_next_line(fd)) != NULL)
    {
        x = 0;
        while (mapy.mapp[y][x] != '\0')
        {
            if (mapy.mapp[y][x] == '1' ) // texture1 = mur
                mlx_image_to_window(mlx, textureInfoArray[0].img, x * TILE_SIZE, y * TILE_SIZE);
            if (mapy.mapp[y][x] == '0' || mapy.mapp[y][x] == 'C' || mapy.mapp[y][x] == 'P' || mapy.mapp[y][x] == 'Y' || mapy.mapp[y][x] == 'W' || mapy.mapp[y][x] == 'F') // texture = sol
                mlx_image_to_window(mlx, textureInfoArray[1].img, x * TILE_SIZE, y * TILE_SIZE);
            if (mapy.mapp[y][x] == 'E' ) // texture3 = sortie
                mlx_image_to_window(mlx, textureInfoArray[3].img, x * TILE_SIZE, y * TILE_SIZE);
            if (mapy.mapp[y][x] == 'Y' ) // texture5 = echelle
                mlx_image_to_window(mlx, textureInfoArray[5].img, x * TILE_SIZE, y * TILE_SIZE);
            if (mapy.mapp[y][x] == 'W' ) // texture6 = support
                mlx_image_to_window(mlx, textureInfoArray[6].img, x * TILE_SIZE, y * TILE_SIZE);
            if (mapy.mapp[y][x] == 'F' ) // texture = feux
                mlx_image_to_window(mlx, textureInfoArray[7].img, x * TILE_SIZE, y * TILE_SIZE);
            x += 1;
        }
        y += 1;
    }
    close(fd);
    int z = y;
    y = 0;
    while (z > y)
    {
        x = 0;
        while (mapy.mapp[y][x] != '\0')
        {
            if (mapy.mapp[y][x] == 'C' ) // texture2 = collectable
                mlx_image_to_window(mlx, textureInfoArray[2].img, x * TILE_SIZE, y * TILE_SIZE);
            if (mapy.mapp[y][x] == 'P' ) // texture2 = collectable
                mlx_image_to_window(mlx, textureInfoArray[4].img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}
