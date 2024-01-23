/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:56 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/23 20:06:04 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/so_long.h"

mlx_image_t			*normal;
mlx_image_t			*flipped;
mlx_image_t			*background_image;

void	collectible(t_all *all)
{
	size_t	i;

	i = 0;
    while (all->textInf[2].img->count >= i)
	{
		if (all->textInf[2].img->instances[all->textInf[2].img->count
			- i].enabled == true
			&& all->textInf[2].img->instances[all->textInf[2].img->count
			- i].x == all->textInf[4].img->instances[0].x
			&& all->textInf[2].img->instances[all->textInf[2].img->count
			- i].y == all->textInf[4].img->instances[0].y)
		{
			all->textInf[2].img->instances[all->textInf[2].img->count
				- i].enabled = false;
			all->mapy.nb_c++;
		}
		i++;
	}
    if (all->textInf[2].img->count == all->mapy.nb_c)
    {
        all->textInf[3].img->enabled = false;
        all->textInf[13].img->enabled = true;
    }
}

bool	jump(int x, int y, t_all *all)
{
	int	mapX;
	int	mapY;

	mapX = x / 32;
	mapY = y / 32;
	if (mapY < (all->mapy.nb_l - 1))
	{
		if (all->mapy.mapp[mapY + 1][mapX] != 'W' && all->mapy.mapp[mapY + 1][mapX] != '1'
			&& all->mapy.mapp[mapY + 1][mapX] != 'Y')
			return (false);
	}
	return (true);
}

int	notladder(int x, int y, t_all *all)
{
	int	mapX;
	int	mapY;

	mapX = x / 32;
	mapY = y / 32;
	if (all->mapy.mapp[mapY][mapX] != 'Y')
		return (0);
	return (1);
}

unsigned long long	getCurrentTimeInMilliseconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((unsigned long long)(tv.tv_sec) * 1000
		+ (unsigned long long)(tv.tv_usec) / 1000);
}

int	isPositionValid(int x, int y, t_all *all)
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
	t_all                       *all;
	mlx_image_t					*img;
	static unsigned long long	jumpTime = 0;
	static unsigned long long	lastMoveTime = 0;
	unsigned long long			currentTime;
	int							newX;
	int							newY;
	
	all = param;
	currentTime = getCurrentTimeInMilliseconds();
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(all->mlx);
	newX = all->textInf[4].img->instances->x;
	newY = all->textInf[4].img->instances->y;
	collectible(all);
    mouvBarrel(all);
	if (!isPositionValid(newX, newY + 32, all) || notladder(newX, newY, all)
		|| notladder(newX, newY + 32, all))
	{
		all->move.gravity = 1;
	}
	// if (mapy.mapp[newY / 32][newX / 32] == 'E'
	// 	&& (all.textInf[2].img->count == mapy.nb_c))
	// {
	// 	mlx_close_window(all->mlx);
	// }
	if (isPositionValid(newX, newY + 32, all) && !(notladder(newX, newY + 32, all))
		&& currentTime - lastMoveTime >= 99)
	{
		if (jump(newX, newY + 32, all))
		{
			if (jumpTime == 3)
			{
				newY += 32;
				jumpTime = 0;
			}
			jumpTime++;
		}
		else
			newY += 32;
	}
	if (currentTime - lastMoveTime >= 100)
	{
		if (mlx_is_key_down(all->mlx, MLX_KEY_W) && all->move.gravity == 1)
		{
			newY -= 32;
			all->move.gravity = 0;
		}
		if (mlx_is_key_down(all->mlx, MLX_KEY_S))
			newY += 32;
		if (mlx_is_key_down(all->mlx, MLX_KEY_A))
		{
			img = flipped;
			newX -= 32;
			all->textInf[4].img->enabled = false;
			all->textInf[12].img->enabled = true;
			// mlx_clear(mlx, flipped);
		}
		if (mlx_is_key_down(all->mlx, MLX_KEY_D))
		{
			img = normal;
			newX += 32;
			all->textInf[12].img->enabled = false;
			all->textInf[4].img->enabled = true;
			// mlx_delete_image(all->mlx, normal);
		}
		if (isPositionValid(newX, newY, all))
		{
			// Mettre à jour la position du personnage uniquement si la nouvelle position est valide
			all->textInf[4].img->instances[0].x = newX;
			all->textInf[4].img->instances[0].y = newY;
			all->textInf[12].img->instances[0].x = newX;
			all->textInf[12].img->instances[0].y = newY;
			lastMoveTime = currentTime;
		}
	}
}
