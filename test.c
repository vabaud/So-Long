/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/17 17:18:45 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"

#define WIN_WIDTH 1248
#define WIN_HEIGHT 512

TextureInfo textureInfoArray[14];

// unsigned long long getCurrentTimeInMilliseconds() {
//     struct timeval tv;
//     gettimeofday(&tv, NULL);
//     return (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
// }

// int isPositionValid(int x, int y) {
//     // Vérifiez si la nouvelle position (x, y) ne correspond pas à un mur (représenté par '1' dans la carte)
//     int mapX = x / 16;
//     int mapY = y / 16;
//     if (mapy.mapp[mapY][mapX] != 'W' && mapy.mapp[mapY][mapX] != '1')
//         return 1;
//     return 0;
// }

// int notladder(int x, int y)
// {
//     int mapX = x / 16;
//     int mapY = y / 16;
//     if (mapy.mapp[mapY][mapX] != 'Y')
//         return 0;
//     return 1;
// }

//  void ft_hook(void* param) {
// 	mlx_t* mlx = param;

// 	static unsigned long long lastMoveTime = 0;
// 	unsigned long long currentTime = getCurrentTimeInMilliseconds();
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	int newX = textureInfoArray[4].img->instances->x;
// 	int newY = textureInfoArray[4].img->instances->y;
// 	if (isPositionValid(newX, newY + 16) && !(notladder(newX, newY + 16)))
// 		newY += 16;
// 	if (currentTime - lastMoveTime >= 350) {
// 		if (mlx_is_key_down(mlx, MLX_KEY_W))
// 			newY -= 16;
// 		if (mlx_is_key_down(mlx, MLX_KEY_S))
// 			newY += 16;
// 		if (mlx_is_key_down(mlx, MLX_KEY_A))
// 			newX -= 16;
// 		if (mlx_is_key_down(mlx, MLX_KEY_D))
// 			newX += 16;
// 		// Vérifier la collision avec les murs
//         if (isPositionValid(newX, newY)) {
//             // Mettre à jour la position du personnage uniquement si la nouvelle position est valide
// 			textureInfoArray[4].img->instances->x = newX;
// 			textureInfoArray[4].img->instances->y = newY;
// 		}
// 		lastMoveTime = currentTime;
// 	}
// }

extern mlx_image_t* normal;  // Face normale = droite
extern mlx_image_t* flipped; // Face inversée = gauche

void initializeTextures(mlx_t* mlx) {
    int i = 0;
    textureInfoArray[0].texture = mlx_load_png("png/rock32.png");
    textureInfoArray[1].texture = mlx_load_png("png/back32.png");
    textureInfoArray[2].texture = mlx_load_png("png/banana32.png");
    textureInfoArray[3].texture = mlx_load_png("png/doorclose32.png");
    textureInfoArray[4].texture = mlx_load_png("png/kong32.png");
    textureInfoArray[5].texture = mlx_load_png("png/ladder32.png");
    textureInfoArray[6].texture = mlx_load_png("png/bloc32.png");
    textureInfoArray[7].texture = mlx_load_png("png/fire32.png");
    textureInfoArray[8].texture = mlx_load_png("png/1barrel32.png");
    textureInfoArray[9].texture = mlx_load_png("png/2barrel32.png");
    textureInfoArray[10].texture = mlx_load_png("png/3barrel32.png");
    textureInfoArray[11].texture = mlx_load_png("png/4barrel32.png");
    textureInfoArray[12].texture = mlx_load_png("png/reversekong32.png");
    textureInfoArray[13].texture = mlx_load_png("png/dooropen32.png");


	while (i < 14)
	{
		textureInfoArray[i].img = mlx_texture_to_image(mlx, textureInfoArray[i].texture);
		mlx_delete_texture(textureInfoArray[i].texture);
		i++;
	}
}



int main(void)  
{
    mlx_t* mlx;

    mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "So_Long", true);
    if (!mlx)
        return 1;
    initializeTextures(mlx);
    int fd = open("maps/maps.ber", O_RDONLY);  // Ouvre le fichier en lecture seule

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
    aff_map(fd, mlx);
    close(fd);
    // Affichage de la carte
    mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
    // mlx_delete_image(mlx, normal);
    // mlx_delete_image(mlx, flipped);
	mlx_terminate(mlx);

	return 0;
}
