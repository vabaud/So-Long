/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:56 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/14 19:34:39 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/so_long.h"


mlx_image_t* normal;
mlx_image_t* flipped;


void init_character_images(mlx_t* mlx) {
	mlx_texture_t* texture_normal = mlx_load_png("png/kong2.png");
	normal = mlx_texture_to_image(mlx, texture_normal);
	mlx_delete_texture(texture_normal);

	mlx_texture_t* texture_flipped = mlx_load_png("png/reversekong.png");
	flipped = mlx_texture_to_image(mlx, texture_flipped);
	mlx_delete_texture(texture_flipped);
}

int notladder(int x, int y)
{
	int mapX = x / 16;
	int mapY = y / 16;
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
    int mapX = x / 16;
    int mapY = y / 16;
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
	
	if (isPositionValid(newX, newY + 16) && !(notladder(newX, newY + 16)))
		newY += 16;
	if (currentTime - lastMoveTime >= 350) {
		if (mlx_is_key_down(mlx, MLX_KEY_W))
			newY -= 16;
		if (mlx_is_key_down(mlx, MLX_KEY_S))
			newY += 16;
		if (mlx_is_key_down(mlx, MLX_KEY_A))
		{
		newX -= 16;
		img = flipped;
		}
		if (mlx_is_key_down(mlx, MLX_KEY_D))
		{
			newX += 16;
			img = normal;
		}
		if (isPositionValid(newX, newY))
		{
			// Mettre à jour la position du personnage uniquement si la nouvelle position est valide
			textureInfoArray[4].img->instances[0].x = newX;
			textureInfoArray[4].img->instances[0].y = newY;

			if (img == flipped)
				mlx_image_to_window(mlx, flipped, newX, newY);
			else
				mlx_image_to_window(mlx, normal, newX, newY);
		}
		lastMoveTime = currentTime;
	}
}





// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;
//     mlx_image_t* current_img = img4; // Image par défaut

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 	mlx_close_window(mlx);

// 	int newX = textureInfoArray[4].img->instances->x;
// 	int newY = textureInfoArray[4].img->instances->y;
// 	if (isPositionValid(newX, newY + 16) && !(notladder(newX, newY + 16)))
// 		newY += 16;
// 	if (mlx_is_key_down(mlx, MLX_KEY_W))
// 		current_img->instances->y -= 16;
// 	if (mlx_is_key_down(mlx, MLX_KEY_S))
// 		current_img->instances->y += 16;
// 	if (mlx_is_key_down(mlx, MLX_KEY_A)) {
// 		current_img->instances->x -= 16;
//         current_img = img12; // Changez pour l'image inversée
//     }
// 	if (mlx_is_key_down(mlx, MLX_KEY_D)) {
// 		current_img->instances->x += 16;
//         current_img = img4; // Retour à l'image normale
//     }

//     mlx_image_to_window(mlx, current_img, current_img->instances->x, current_img->instances->y);
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;
//     mlx_texture_t* texture4 = mlx_load_png("png/king.png");
//     mlx_image_t* img4 = mlx_texture_to_image(mlx, texture4);
//     mlx_delete_texture(texture4);
//     mlx_image_to_window(mlx, img4, 0 * TILE_SIZE, 0 * TILE_SIZE);
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_W))
// 		img4->instances->y -= 16;
// 	if (mlx_is_key_down(mlx, MLX_KEY_S))
// 		img4->instances->y += 16;
// 	if (mlx_is_key_down(mlx, MLX_KEY_A))
// 		img4->instances->x -= 16;
// 	if (mlx_is_key_down(mlx, MLX_KEY_D))
// 		img4->instances->x += 16;
   
// }






































// void mlx_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }



// #include "MLX42/include/MLX42/MLX42.h"
// #include <stdbool.h>

// #define WIN_WIDTH 800
// #define WIN_HEIGHT 600
// #define TILE_SIZE 16
// #define SPEED 5

// typedef struct {
//     int x;
//     int y;
//     mlx_image_t* img;
//     mlx_t* mlx;
// } GameData;

// void handle_key(mlx_key_data_t keydata, void *param) {
//     GameData *game = (GameData *)param;

//     if (keydata.action == MLX_PRESS) {
//         switch (keydata.key) {
//             case MLX_KEY_UP:
//                 game->y -= SPEED;
//                 break;
//             case MLX_KEY_DOWN:
//                 game->y += SPEED;
//                 break;
//             case MLX_KEY_LEFT:
//                 game->x -= SPEED;
//                 break;
//             case MLX_KEY_RIGHT:
//                 game->x += SPEED;
//                 break;
//             default:
//                 break;
//         }
//     }
// }

// void update_screen(void* param) {
//     GameData *game = (GameData *)param;
//     mlx_image_to_window(game->mlx, game->img, game->x, game->y);
// }

// int main(void) {
//     GameData game;
//     game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "So Long", false);
//     if (!game.mlx) {
//         return 1;
//     }

//     game.x = WIN_WIDTH / 2;
//     game.y = WIN_HEIGHT / 2;

//     // Charger l'image du personnage
//     mlx_texture_t* texture = mlx_load_png("png/Character.png");
//     if (!texture) {
//         mlx_terminate(game.mlx);
//         return 1;
//     }

//     game.img = mlx_texture_to_image(game.mlx, texture);
//     mlx_delete_texture(texture);
//     if (!game.img) {
//         mlx_terminate(game.mlx);
//         return 1;
//     }

//     mlx_key_hook(game.mlx, &handle_key, &game);
//     mlx_loop_hook(game.mlx, &update_screen, &game);

//     mlx_loop(game.mlx);
//     mlx_terminate(game.mlx);
//     return 0;
// }
