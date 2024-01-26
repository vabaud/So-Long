/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:56 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/26 14:30:43 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/so_long.h"

void	collectible(t_all *all)
{
	size_t	i;
	size_t	nbr;

	nbr = all->textinf[2].img->count;
	i = 0;
	while (nbr >= i)
	{
		if (all->textinf[2].img->instances[nbr - i].enabled == true && all->textinf[2].img->instances[nbr
			- i].x == all->textinf[4].img->instances[0].x
			&& all->textinf[2].img->instances[nbr
			- i].y == all->textinf[4].img->instances[0].y)
		{
			all->textinf[2].img->instances[nbr - i].enabled = false;
			all->mapy.nb_c++;
		}
		i++;
	}
	if (nbr == all->mapy.nb_c)
	{
		all->textinf[3].img->enabled = false;
		all->textinf[13].img->enabled = true;
	}
}

unsigned long long	getCurrentTimeInMilliseconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((unsigned long long)(tv.tv_sec) * 1000
		+ (unsigned long long)(tv.tv_usec) / 1000);
}

int	is_pos_valid(int x, int y, t_all *all)
{
	int	mapX;
	int	mapY;

	mapX = x / 32;
	mapY = y / 32;
	if (all->mapy.mapp[mapY][mapX] != 'W' && all->mapy.mapp[mapY][mapX] != '1')
		return (1);
	return (0);
}

void	ft_hook(void *param)
{
	t_all						*all;
	static unsigned long long	lastMoveTime = 0;
	unsigned long long			currentTime;
	int							newX;
	int							newY;

	all = param;
	currentTime = getCurrentTimeInMilliseconds();
	newX = all->textinf[4].img->instances->x;
	newY = all->textinf[4].img->instances->y;
	collectible(all);
	mouv_barrel(all);
	if (all->mapy.mapp[newY / 32][newX / 32] == 'E'
		&& (all->textinf[2].img->count == all->mapy.nb_c))
		mlx_close_window(all->mlx);
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE) || (all->textinf[4].img->instances[0].x == all->textinf[8].img->instances[0].x && all->textinf[4].img->instances[0].y == all->textinf[8].img->instances[0].y))
		mlx_close_window(all->mlx);
	if (currentTime - lastMoveTime >= 100)
	{
		if (mlx_is_key_down(all->mlx, MLX_KEY_W))
			newY -= 32;
		if (mlx_is_key_down(all->mlx, MLX_KEY_S))
			newY += 32;
		if (mlx_is_key_down(all->mlx, MLX_KEY_A))
		{
			newX -= 32;
			all->textinf[4].img->enabled = false;
			all->textinf[12].img->enabled = true;
		}
		if (mlx_is_key_down(all->mlx, MLX_KEY_D))
		{
			newX += 32;
			all->textinf[12].img->enabled = false;
			all->textinf[4].img->enabled = true;
		}
		if (is_pos_valid(newX, newY, all))
		{
			all->textinf[4].img->instances[0].x = newX;
			all->textinf[4].img->instances[0].y = newY;
			all->textinf[12].img->instances[0].x = newX;
			all->textinf[12].img->instances[0].y = newY;
            all->move.nb_move++;
			lastMoveTime = currentTime;
		}
	}
}
