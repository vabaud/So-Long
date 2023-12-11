// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mouv_perso.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/12/08 20:49:44 by tbihoues          #+#    #+#             */
// /*   Updated: 2023/12/08 22:43:50 by tbihoues         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

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
