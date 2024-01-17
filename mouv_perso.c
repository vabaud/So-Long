/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:56 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/17 18:03:52 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/so_long.h"

mlx_image_t			*normal;
mlx_image_t			*flipped;
mlx_image_t			*background_image;

void	collectible(void)
{
	size_t	i;

	i = 0;
    while (textureInfoArray[2].img->count >= i)
	{
		if (textureInfoArray[2].img->instances[textureInfoArray[2].img->count
			- i].enabled == true
			&& textureInfoArray[2].img->instances[textureInfoArray[2].img->count
			- i].x == textureInfoArray[4].img->instances[0].x
			&& textureInfoArray[2].img->instances[textureInfoArray[2].img->count
			- i].y == textureInfoArray[4].img->instances[0].y)
		{
			textureInfoArray[2].img->instances[textureInfoArray[2].img->count
				- i].enabled = false;
			mapy.nb_c++;
		}
		i++;
	}
    if (textureInfoArray[2].img->count == mapy.nb_c)
    {
        textureInfoArray[3].img->enabled = false;
        textureInfoArray[13].img->enabled = true;
    }
}

bool	jump(int x, int y)
{
	int	mapX;
	int	mapY;

	mapX = x / 32;
	mapY = y / 32;
	if (mapY < (mapy.maxY - 1))
	{
		if (mapy.mapp[mapY + 1][mapX] != 'W' && mapy.mapp[mapY + 1][mapX] != '1'
			&& mapy.mapp[mapY + 1][mapX] != 'Y')
			return (false);
	}
	return (true);
}

int	notladder(int x, int y)
{
	int	mapX;
	int	mapY;

	mapX = x / 32;
	mapY = y / 32;
	if (mapy.mapp[mapY][mapX] != 'Y')
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

int	isPositionValid(int x, int y)
{
	int	mapX;
	int	mapY;

	mapX = x / 32;
	mapY = y / 32;
	if (mapy.mapp[mapY][mapX] != 'W' && mapy.mapp[mapY][mapX] != '1')
		return (1);
	return (0);
}

void	ft_hook(void *param)
{
	mlx_t						*mlx;
	mlx_image_t					*img;
	static unsigned long long	jumpTime = 0;
	static unsigned long long	lastMoveTime = 0;
	unsigned long long			currentTime;
	int							newX;
	int							newY;

	mlx = param;
	currentTime = getCurrentTimeInMilliseconds();
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	newX = textureInfoArray[4].img->instances->x;
	newY = textureInfoArray[4].img->instances->y;
	// mlx_put_image_to_window(mlx, mlx->win, img, newX, newY);
	collectible();
    mouvBarrel();
    if (textureInfoArray[8].img->instances->x == textureInfoArray[4].img->instances->x && textureInfoArray[8].img->instances->y == textureInfoArray[4].img->instances->y)
    {
        mlx_close_window(mlx);
    }    
	if (!isPositionValid(newX, newY + 32) || notladder(newX, newY)
		|| notladder(newX, newY + 32))
	{
		mapy.gravity = 1;
	}
	if (mapy.mapp[newY / 32][newX / 32] == 'E'
		&& (textureInfoArray[2].img->count == mapy.nb_c))
	{
		mlx_close_window(mlx);
	}
	if (isPositionValid(newX, newY + 32) && !(notladder(newX, newY + 32))
		&& currentTime - lastMoveTime >= 99)
	{
		if (jump(newX, newY + 32))
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
		if (mlx_is_key_down(mlx, MLX_KEY_W) && mapy.gravity == 1)
		{
			newY -= 32;
			mapy.gravity = 0;
		}
		if (mlx_is_key_down(mlx, MLX_KEY_S))
			newY += 32;
		if (mlx_is_key_down(mlx, MLX_KEY_A))
		{
			img = flipped;
			newX -= 32;
			textureInfoArray[4].img->enabled = false;
			textureInfoArray[12].img->enabled = true;
			// mlx_clear(mlx, flipped);
		}
		if (mlx_is_key_down(mlx, MLX_KEY_D))
		{
			img = normal;
			newX += 32;
			textureInfoArray[12].img->enabled = false;
			textureInfoArray[4].img->enabled = true;
			// mlx_delete_image(mlx, normal);
		}
		if (isPositionValid(newX, newY))
		{
			// Mettre à jour la position du personnage uniquement si la nouvelle position est valide
			textureInfoArray[4].img->instances[0].x = newX;
			textureInfoArray[4].img->instances[0].y = newY;
			textureInfoArray[12].img->instances[0].x = newX;
			textureInfoArray[12].img->instances[0].y = newY;
			lastMoveTime = currentTime;
		}
	}
}
