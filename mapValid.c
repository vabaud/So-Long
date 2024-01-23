/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:06:50 by vabaud            #+#    #+#             */
/*   Updated: 2024/01/23 20:03:10 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"

void isMapValid(t_all *all)
{
    int y = 0;
    int x = 0;
    while (y < all->mapy.nb_l)
    {
        x = 0;
        while (x < all->mapy.maxX - 1 && (y == 0 || y == (all->mapy.nb_l - 1)))
        {
            if (all->mapy.mapp[y][x] != '1')
                mlx_close_window(all->mlx);
            x++;
        }
        if (y > 0 && y < all->mapy.nb_l - 1)
        {
            if (all->mapy.mapp[y][0] != '1' || all->mapy.mapp[y][all->mapy.maxX - 2] != '1')
                mlx_close_window(all->mlx);
        }
        y++;
    }
}
