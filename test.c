/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/11 17:11:37 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"
#include <stdbool.h>
#include <sys/time.h> 

#define WIN_WIDTH 800
#define WIN_HEIGHT 400

TextureInfo textureInfoArray[13];

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

int notladder(int x, int y)
{
    int mapX = x / 16;
    int mapY = y / 16;
    if (mapy.mapp[mapY][mapX] != 'Y')
        return 0;
    return 1;
}

void ft_hook(void* param) {
    mlx_t* mlx = param;

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
            newX -= 16;
        if (mlx_is_key_down(mlx, MLX_KEY_D))
            newX += 16;
    // Vérifier la collision avec les murs
        if (isPositionValid(newX, newY)) {
            // Mettre à jour la position du personnage uniquement si la nouvelle position est valide
            textureInfoArray[4].img->instances->x = newX;
            textureInfoArray[4].img->instances->y = newY;
        }
        lastMoveTime = currentTime;
    }
}

void initializeTextures(mlx_t* mlx) {
    int i = 0;
    textureInfoArray[0].texture = mlx_load_png("png/rock.png");
    textureInfoArray[1].texture = mlx_load_png("png/back2.png");
    textureInfoArray[2].texture = mlx_load_png("png/banana.png");
    textureInfoArray[3].texture = mlx_load_png("png/door.png");
    textureInfoArray[4].texture = mlx_load_png("png/kingkong.png");
    textureInfoArray[5].texture = mlx_load_png("png/ladder.png");
    textureInfoArray[6].texture = mlx_load_png("png/bloc.png");
    textureInfoArray[7].texture = mlx_load_png("png/fire.png");
    textureInfoArray[8].texture = mlx_load_png("png/barrel1.png");
    textureInfoArray[9].texture = mlx_load_png("png/barrel2.png");
    textureInfoArray[10].texture = mlx_load_png("png/barrel3.png");
    textureInfoArray[11].texture = mlx_load_png("png/barrel4.png");


    while (i < 12)
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
    {
        return 1;
    }
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
    mlx_terminate(mlx);

    return 0;
}





// int		close_window(t_env *env)
// {
// 	exit_game(env, 0);
// 	return(0);
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "MLX42/include/MLX42/MLX42.h"

// #define WIDTH 512
// #define HEIGHT 512

// static mlx_image_t* image;

// // -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize()
// {
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				0xFF, // R
// 				0x00, // G
// 				0x00, // B
// 				0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
//  	image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// // -----------------------------------------------------------------------------

// // void test()
// // {
// //     printf("une touche a ete pressee\n");
// //     return;
// // }

// int32_t main()
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);
//     //mlx_key_hook(mlx, test, NULL);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
