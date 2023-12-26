/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/26 14:23:47 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/time.h> 


//jai ajouter la fonction pour atoriser a monter que sil est surt lechelle sinon il ne monte pas 
// je vais maintenant voir pour les consomables 

#define WIN_WIDTH 800
#define WIN_HEIGHT 400

TextureInfo textureInfoArray[8];
int canClimbLadder(int x, int y);

int isPositionValid(int x, int y) {
    int mapX = x / 16;
    int mapY = y / 16;
    char currentTile = mapy.mapp[mapY][mapX];

    if (currentTile != 'W' && currentTile != '1') {
        if (currentTile == 'Y') {
            // monter que si la case cest echelle ('Y')
            if (!canClimbLadder(x, y)) {
                return 0;
            }
        }
        return 1; // position valide
    }
    return 0; // position non valide (mur)
}

int canClimbLadder(int x, int y) {
    int mapX = x / 16;
    int mapY = y / 16;
    return (mapy.mapp[mapY][mapX] == 'Y');
}

unsigned long long getCurrentTimeInMilliseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
}

void ft_hook(void* param) {
    mlx_t* mlx = param;

    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);

    static unsigned long long lastMoveTime = 0;
    unsigned long long currentTime = getCurrentTimeInMilliseconds(100);

    int moveAmount = 16;
    int newX = textureInfoArray[4].img->instances->x;
    int newY = textureInfoArray[4].img->instances->y;

    if (currentTime - lastMoveTime >= 350) {
        if (mlx_is_key_down(mlx, MLX_KEY_W)) {
            int mapX = newX / 16;
            int mapY = (newY - moveAmount) / 16;

            // Vérifiez si la nouvelle position est sur une échelle ('Y')
            if (mapy.mapp[mapY][mapX] == 'Y') {
                newY -= moveAmount; // Permet la montée sur l'échelle
            }
        }
        if (mlx_is_key_down(mlx, MLX_KEY_S)) {
            newY += moveAmount;
        }
        if (mlx_is_key_down(mlx, MLX_KEY_A)) {
            newX -= moveAmount;
        }
        if (mlx_is_key_down(mlx, MLX_KEY_D)) {
            newX += moveAmount;
        }

        if (isPositionValid(newX, newY)) {
            textureInfoArray[4].img->instances->x = newX;
            textureInfoArray[4].img->instances->y = newY;
            lastMoveTime = currentTime;
        }
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

    while (i < 8) {
        textureInfoArray[i].img = mlx_texture_to_image(mlx, textureInfoArray[i].texture);
        mlx_delete_texture(textureInfoArray[i].texture);
        i++;
    }
}

int main(void) {
    mlx_t* mlx;

    mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "So_Long", true);
    if (!mlx) {
        return 1;
    }
    initializeTextures(mlx);
    int fd = open("maps/maps.ber", O_RDONLY);  // Ouvre le fichier en lecture seule

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    aff_map(fd, mlx);
    close(fd);

    mlx_loop_hook(mlx, ft_hook, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return 0;
}