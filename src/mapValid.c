/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:06:50 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/07 08:06:48 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	is_map_valid(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < all->mapy.nb_l)
	{
		x = 0;
		while (x < all->mapy.max_x - 1 && (y == 0 || y == (all->mapy.nb_l - 1)))
		{
			if (all->mapy.mapp[y][x] != '1')
				mlx_close_window(all->mlx);
			x++;
		}
		if (y > 0 && y < all->mapy.nb_l - 1)
		{
			if (all->mapy.mapp[y][0] != '1' || all->mapy.mapp[y][all->mapy.max_x
				- 2] != '1')
				mlx_close_window(all->mlx);
		}
		y++;
	}
    if (flood(all, all->textinf[4].img->instances[0].x + 32, all->textinf[4].img->instances->y) == false)
        mlx_close_window(all->mlx);
    all->mapy.nb_c = 0;
}

bool flood(t_all *all, int x, int y)
{
    printf("%d    %zu\n", all->mapy.nb_e, all->mapy.nb_c);
    if (all->mapy.mapp[y / 32][x / 32] == 'C')
    {
        all->mapy.nb_c++;
        all->mapy.mapp[y / 32][x / 32] = 'A';
    }
    else if (all->mapy.mapp[y / 32][x / 32] == 'E')
        all->mapy.nb_e = 1;
    if (all->mapy.mapp[y / 32][x / 32] == '0') {
        all->mapy.mapp[y / 32][x / 32] = 'Y';
        flood(all, x + 32, y);
        flood(all, x - 32, y);
        flood(all, x, y + 32);
        flood(all, x, y - 32);
    }
    if ((all->mapy.nb_e == 1) && (all->mapy.nb_c == all->textinf[2].img->count))
        return (true);
    else
        return (false);
}