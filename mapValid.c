/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:06:50 by vabaud            #+#    #+#             */
/*   Updated: 2024/01/18 13:40:30 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"

void isMapValid(mlx_t *mlx)
{
    int y = 0;
    int x = 0;
    while (y <= mapy.maxY)
    {
        x = 0;
        while (x < mapy.maxX && (y == 0 || y == mapy.maxY - 1))
        {
            if (mapy.mapp[y][x] != '1')
                mlx_close_window(mlx);
            x++;
        }
        if (y > 0 && y < mapy.maxY - 1)
        {
            if (mapy.mapp[y][0] != '1' || mapy.mapp[y][mapy.maxX - 1] != '1')
                mlx_close_window(mlx);
        }
        y++;
    }
}
