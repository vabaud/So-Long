/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/12 00:50:57 by parallels        ###   ########.fr       */
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

// Structure pour représenter un tonneau
typedef struct s_barrel {
    int x, y;       // Position actuelle du tonneau
    int frame;      // Frame actuelle de l'animation
} t_barrel;

// Fonction pour mettre à jour la position du tonneau
void update_barrel_position(t_barrel *barrel, int speed) {
    barrel->x -= speed; // Déplacer le tonneau vers la gauche
    if (barrel->x < 0) {
        barrel->x = 0; // Réinitialiser la position si elle sort de l'écran
    }
}

// Fonction pour mettre à jour la frame de l'animation du tonneau
void update_barrel_animation(t_barrel *barrel, int total_frames) {
    barrel->frame = (barrel->frame + 1) % total_frames; // Alterner entre 0 et 3 si total_frames est 4
}

// Appelé à chaque frame par votre boucle de jeu
void game_update(t_barrel *barrels, int num_barrels, int speed) {
    for (int i = 0; i < num_barrels; i++) {
        update_barrel_position(&barrels[i], speed);
        update_barrel_animation(&barrels[i], 4); // Si vous avez 4 frames
        // Dessinez le tonneau ici en utilisant barrel->frame pour choisir la bonne image
    }
}

// Dans votre fonction principale ou initialisation du jeu
t_barrel barrels[4]; // Définir NUM_BARRELS comme le nombre de tonneaux
// Initialiser les tonneaux ici...
