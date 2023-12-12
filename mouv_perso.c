/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:56 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/12 15:53:41 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/so_long.h"
#include <stdbool.h>

// typedef struct
// {
//     void *mlx_ptr;
//     void *win_ptr;
//     void *img_ptr;
//     int x;
//     int y;
// } 
// app_t;

// void draw_image(app_t *app)
// {
//     mlx_clear_window(app->mlx_ptr, app->win_ptr);
//     mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, app->x, app->y);
// }

void ft_hook(void* param)
{
	mlx_t* mlx = param;
    mlx_texture_t* texture4 = mlx_load_png("png/king.png");
    mlx_image_t* img4 = mlx_texture_to_image(mlx, texture4);
    mlx_delete_texture(texture4);

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		character.y -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		character.y += 1;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		character.x -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		character.x += 1;
    mlx_image_to_window(mlx, img4, character.x * TILE_SIZE, character.y * TILE_SIZE);
}

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
