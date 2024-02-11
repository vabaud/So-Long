/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:06:50 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/11 12:10:23 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	is_map_valid(t_all *all)
{
    isrectangular(all);
	isok(all);
	if (all->mapy.nb_c < 1 || all->mapy.nb_e != 1 || all->mapy.nb_p != 1
		|| all->mapy.nb_other > 0)
	{
		free_tab(all->mapy.mapp);
		mlx_terminate(all->mlx);
		exit(EXIT_FAILURE);
	}
	all->mapy.nb_c = 0;
	if (flood(all, all->textinf[4].img->instances[0].x + 32,
			all->textinf[4].img->instances->y) == false)
		mlx_close_window(all->mlx);
	closemap(all);
	all->mapy.nb_c = 0;
}

void	closemap(t_all *all)
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

void	isok(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->mapy.nb_l)
	{
		x = 0;
		while (all->mapy.mapp[y][x])
		{
			if (all->mapy.mapp[y][x] == 'P')
				all->mapy.nb_p++;
			if (all->mapy.mapp[y][x] == 'C')
				all->mapy.nb_c++;
			if (all->mapy.mapp[y][x] == 'E')
				all->mapy.nb_e++;
			if (all->mapy.mapp[y][x] != 'E' && all->mapy.mapp[y][x] != 'C'
				&& all->mapy.mapp[y][x] != 'P' && all->mapy.mapp[y][x] != '1'
				&& all->mapy.mapp[y][x] != '0' && all->mapy.mapp[y][x] != '2'
				&& all->mapy.mapp[y][x] != '\n')
				all->mapy.nb_other++;
			x++;
		}
		y++;
	}
}

bool	flood(t_all *all, int x, int y)
{
	if (all->mapy.mapp[y / 32][x / 32] == 'C')
	{
		all->mapy.nb_c++;
		all->mapy.mapp[y / 32][x / 32] = 'A';
	}
	else if (all->mapy.mapp[y / 32][x / 32] == 'E')
		all->mapy.nb_e = 1;
	if (all->mapy.mapp[y / 32][x / 32] == '0')
	{
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

void isrectangular(t_all *all)
{
    int y;
    size_t len;

    y = 0;
    len = ft_strlen(all->mapy.mapp[y]);
    y++;
    while (y < all->mapy.nb_l)
    {
        if (ft_strlen(all->mapy.mapp[y]) != len)
        {
            free_tab(all->mapy.mapp);
            mlx_terminate(all->mlx);
            exit(EXIT_FAILURE);
        }
        y++;
    }
}
