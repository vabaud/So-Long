/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:06:50 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/02 22:42:08 by tbihoues         ###   ########.fr       */
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
}
