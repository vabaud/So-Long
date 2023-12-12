/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/12 16:20:51 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"
#include <stdbool.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 400

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
    // Charger une image (remplacer avec votre propre image)

    mlx_texture_t* texture = mlx_load_png("png/rock.png");
    mlx_texture_t* texture1 = mlx_load_png("png/back2.png");
    mlx_texture_t* texture2 = mlx_load_png("png/banana.png");
    mlx_texture_t* texture3 = mlx_load_png("png/door.png");
    mlx_texture_t* texture4 = mlx_load_png("png/king.png");
    mlx_texture_t* texture5 = mlx_load_png("png/ladder.png");
    mlx_texture_t* texture6 = mlx_load_png("png/bloc.png");
    mlx_texture_t* texture7 = mlx_load_png("png/fire.png");

	if (!texture || !texture1 || !texture2 || !texture3 || !texture4 || !texture5 || !texture6 || !texture7)
    {
        mlx_terminate(mlx);
        return 1;
    }
    // Charger une texture et l'appliquer sur l'image
    mlx_image_t* img = mlx_texture_to_image(mlx, texture);
    mlx_delete_texture(texture); // Nettoyer la texture après usage
    mlx_image_t* img1 = mlx_texture_to_image(mlx, texture1);
    mlx_delete_texture(texture1);
    mlx_image_t* img2 = mlx_texture_to_image(mlx, texture2);
    mlx_delete_texture(texture2);
    mlx_image_t* img3 = mlx_texture_to_image(mlx, texture3);
    mlx_delete_texture(texture3);
    mlx_image_t* img4 = mlx_texture_to_image(mlx, texture4);
    mlx_delete_texture(texture4);
    mlx_image_t* img5 = mlx_texture_to_image(mlx, texture5);
    mlx_delete_texture(texture5);
    mlx_image_t* img6 = mlx_texture_to_image(mlx, texture6);
    mlx_delete_texture(texture6);
    mlx_image_t* img7 = mlx_texture_to_image(mlx, texture7);
    mlx_delete_texture(texture7);

    if (!img)
    {
        mlx_terminate(mlx);
        return 1;
    }
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
				mlx_image_to_window(mlx, img, x * TILE_SIZE, y * TILE_SIZE);
            if (map[x] == '0' || map[x] == 'C' || map[x] == 'Y' || map[x] == 'W' || map[x] == 'F') // texture = sol
                mlx_image_to_window(mlx, img1, x * TILE_SIZE, y * TILE_SIZE);
            if (map[x] == 'C' ) // texture2 = collectable
				mlx_image_to_window(mlx, img2, x * TILE_SIZE, y * TILE_SIZE);
            if (map[x] == 'E' ) // texture3 = sortie
				mlx_image_to_window(mlx, img3, x * TILE_SIZE, y * TILE_SIZE);
            if (map[x] == 'P' ) // texture4 = king kong
            {
				mlx_image_to_window(mlx, img4, x * TILE_SIZE, y * TILE_SIZE);
            }
			if (map[x] == 'Y' ) // texture5 = echelle
				mlx_image_to_window(mlx, img5, x * TILE_SIZE, y * TILE_SIZE);
			if (map[x] == 'W' ) // texture6 = support
				mlx_image_to_window(mlx, img6, x * TILE_SIZE, y * TILE_SIZE);
			if (map[x] == 'F' ) // texture = feux
				mlx_image_to_window(mlx, img7, x * TILE_SIZE, y * TILE_SIZE);
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
