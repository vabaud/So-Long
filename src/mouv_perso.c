/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:56 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/05 19:59:42 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	collectible(t_all *all)
{
	size_t	i;
	size_t	nbr;

	nbr = all->textinf[2].img->count;
	i = 0;
	while (i < nbr)
	{
		if (all->textinf[2].img->instances[nbr - i - 1].enabled == true
			&& all->textinf[2].img->instances[nbr - i - 1].x
			== all->textinf[4].img->instances[0].x
			&& all->textinf[2].img->instances[nbr - i - 1].y
			== all->textinf[4].img->instances[0].y)
		{
			all->textinf[2].img->instances[nbr - i - 1].enabled = false;
			all->mapy.nb_c++;
		}
		i++;
	}
	if (nbr == all->mapy.nb_c)
	{
		all->textinf[3].img->enabled = false;
		all->textinf[10].img->enabled = true;
	}
}

int	is_pos_valid(int x, int y, t_all *all)
{
	int	mapx;
	int	mapy;

	mapx = x / 32;
	mapy = y / 32;
	if (all->mapy.mapp[mapy][mapx] != '1')
		return (1);
	return (0);
}

void	conditions(t_all *all, int newX, int newY)
{
	if (all->mapy.mapp[newY / 32][newX / 32] == 'E'
		&& (all->textinf[2].img->count == all->mapy.nb_c))
	{
		mlx_close_window(all->mlx);
	}
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(all->mlx);
	}
}

void	movements(t_all *all, int *newX, int *newY)
{
	if (mlx_is_key_down(all->mlx, MLX_KEY_W))
	{
		*newY -= 32;
		aff_nb_move(all, newX, newY);
	}
	if (mlx_is_key_down(all->mlx, MLX_KEY_S))
	{
		*newY += 32;
		aff_nb_move(all, newX, newY);
	}
	if (mlx_is_key_down(all->mlx, MLX_KEY_A))
	{
		*newX -= 32;
		all->textinf[4].img->enabled = false;
		all->textinf[9].img->enabled = true;
		aff_nb_move(all, newX, newY);
	}
	if (mlx_is_key_down(all->mlx, MLX_KEY_D))
	{
		*newX += 32;
		all->textinf[9].img->enabled = false;
		all->textinf[4].img->enabled = true;
		aff_nb_move(all, newX, newY);
	}
}

void	ft_hook(void *param)
{
	t_all	*all;
	int		newx;
	int		newy;

	all = param;
	newx = all->textinf[4].img->instances->x;
	newy = all->textinf[4].img->instances->y;
	collectible(all);
	conditions(all, newx, newy);
	if (all->mapy.nb_enemy > 0)
		mouv_barrel(all);
	movements(all, &newx, &newy);
	usleep(80000);
	if (is_pos_valid(newx, newy, all))
	{
		all->textinf[4].img->instances[0].x = newx;
		all->textinf[4].img->instances[0].y = newy;
		all->textinf[9].img->instances[0].x = newx;
		all->textinf[9].img->instances[0].y = newy;
	}
}
