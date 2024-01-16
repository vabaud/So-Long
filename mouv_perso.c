/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:56 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/16 23:28:22 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/so_long.h"


mlx_image_t* normal;
mlx_image_t* flipped;
mlx_image_t* background_image;

void init_character_images(mlx_t* mlx)
{
	// int i = 0;
	mlx_texture_t* texture_normal = mlx_load_png("png/kong32.png");
	normal = mlx_texture_to_image(mlx, texture_normal);
	mlx_delete_texture(texture_normal);

	mlx_texture_t* texture_flipped = mlx_load_png("png/reversekong32.png");
	flipped = mlx_texture_to_image(mlx, texture_flipped);
	mlx_delete_texture(texture_flipped);
}

int notladder(int x, int y)
{
	int mapX = x / 32;
	int mapY = y / 32;
	if (mapy.mapp[mapY][mapX] != 'Y')
		return 0;
	return 1;
}

unsigned long long getCurrentTimeInMilliseconds() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
}

int isPositionValid(int x, int y) {
    // Vérifiez si la nouvelle position (x, y) ne correspond pas à un mur (représenté par '1' dans la carte)
    int mapX = x / 32;
    int mapY = y / 32;
    if (mapy.mapp[mapY][mapX] != 'W' && mapy.mapp[mapY][mapX] != '1')
        return 1;
    return 0;
}	


void ft_hook(void* param)
{
	mlx_t* mlx = param;
	mlx_image_t* img = flipped;

	static unsigned long long lastMoveTime = 0;
	unsigned long long currentTime = getCurrentTimeInMilliseconds();
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

	int newX = textureInfoArray[4].img->instances->x;
	int newY = textureInfoArray[4].img->instances->y;
	//mlx_put_image_to_window(mlx, mlx->win, img, newX, newY);

	
	if (isPositionValid(newX, newY + 32) && !(notladder(newX, newY + 32))) {
		newY += 32; }
	if (currentTime - lastMoveTime >= 100) {
		if (mlx_is_key_down(mlx, MLX_KEY_W))
			newY -= 32;
		if (mlx_is_key_down(mlx, MLX_KEY_S))
			newY += 32;
		if (mlx_is_key_down(mlx, MLX_KEY_A))
		{
			img = flipped;
			newX -= 32;
			//mlx_clear(mlx, flipped);
		}
		if (mlx_is_key_down(mlx, MLX_KEY_D))
		{
			img = normal;
			newX += 32;
			//mlx_delete_image(mlx, normal);
		}
		if (isPositionValid(newX, newY))
		{
			// Mettre à jour la position du personnage uniquement si la nouvelle position est valide
			textureInfoArray[4].img->instances[0].x = newX;
			textureInfoArray[4].img->instances[0].y = newY;

			// if (img == flipped)
			// 	mlx_image_to_window(mlx, flipped, newX, newY);
		lastMoveTime = currentTime;
		}
	}
}
