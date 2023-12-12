/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/12 19:31:19 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"
#include <stdbool.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 400

void ft_hook(void* param)
{
	mlx_t* mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		textureInfoArray[4].img->instances->y -= 2;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		textureInfoArray[4].img->instances->y += 2;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		textureInfoArray[4].img->instances->x -= 2;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		textureInfoArray[4].img->instances->x += 2;
   
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
    textureInfoArray[0].img = mlx_texture_to_image(mlx, textureInfoArray[0].texture);
    textureInfoArray[1].img = mlx_texture_to_image(mlx, textureInfoArray[1].texture);
    textureInfoArray[2].img = mlx_texture_to_image(mlx, textureInfoArray[2].texture);
    textureInfoArray[3].img = mlx_texture_to_image(mlx, textureInfoArray[3].texture);
    textureInfoArray[4].img = mlx_texture_to_image(mlx, textureInfoArray[4].texture);
    textureInfoArray[5].img = mlx_texture_to_image(mlx, textureInfoArray[5].texture);
    textureInfoArray[6].img = mlx_texture_to_image(mlx, textureInfoArray[6].texture);
    textureInfoArray[7].img = mlx_texture_to_image(mlx, textureInfoArray[7].texture);

    while (i < 8)
    {
        textureInfoArray[i].img = mlx_texture_to_image(mlx, textureInfoArray[i].texture);
        mlx_delete_texture(textureInfoArray[i].texture);
        i++;
    }
}

int main(void)
{
    mlx_t* mlx;
    char *map;
    int y = 0;
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
    while ((map = get_next_line(fd)) != NULL)
    {
        int x = 0;
        while (map[x] != '\0')
        {
			if (map[x] == '1' ) // texture1 = mur
				mlx_image_to_window(mlx, textureInfoArray[0].img, x * TILE_SIZE, y * TILE_SIZE);
			if (map[x] == '0' || map[x] == 'C' || map[x] == 'Y' || map[x] == 'W' || map[x] == 'F') // texture = sol
                mlx_image_to_window(mlx, textureInfoArray[1].img, x * TILE_SIZE, y * TILE_SIZE);
			if (map[x] == 'C' ) // texture2 = collectable
				mlx_image_to_window(mlx, textureInfoArray[2].img, x * TILE_SIZE, y * TILE_SIZE);
			if (map[x] == 'E' ) // texture3 = sortie
				mlx_image_to_window(mlx, textureInfoArray[3].img, x * TILE_SIZE, y * TILE_SIZE);
			if (map[x] == 'P' ) // texture4 = king kong
			{
				mlx_image_to_window(mlx, textureInfoArray[4].img, x * TILE_SIZE, y * TILE_SIZE);
			}
			if (map[x] == 'Y' ) // texture5 = echelle
				mlx_image_to_window(mlx, textureInfoArray[5].img, x * TILE_SIZE, y * TILE_SIZE);
			if (map[x] == 'W' ) // texture6 = support
				mlx_image_to_window(mlx, textureInfoArray[6].img, x * TILE_SIZE, y * TILE_SIZE);
			if (map[x] == 'F' ) // texture = feux
				mlx_image_to_window(mlx, textureInfoArray[7].img, x * TILE_SIZE, y * TILE_SIZE);
            x += 1;
        }
        y += 1;
        free(map);
    }
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
