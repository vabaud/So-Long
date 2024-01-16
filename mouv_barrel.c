/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_barrel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:42:43 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/16 18:05:29 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"

#define NUM_TONNEAUX 4
#define VITESSE 1
#define TOTAL_FRAMES 4
// #define window_width 0
//#define start_y 0


void initialiser_tonneaux(t_barrel *tonneaux, int window_width, int start_y)
{
    for (int i = 0; i < NUM_TONNEAUX; i++) {
        tonneaux[i].x = window_width;
        tonneaux[i].y = start_y;
        tonneaux[i].frame = 0;
    }
}

// Fonction pour mettre à jour la position du tonneau
void update_barrel_position(t_barrel *tonneau, int window_width, int largeur_tonneau)
{
    tonneau->x -= VITESSE; // Déplacer le tonneau vers la gauche
    if (tonneau->x < -largeur_tonneau) {
        tonneau->x = window_width; // Remettre à droite de l'écran
    }
}

// Fonction pour mettre à jour la frame de l'animation du tonneau
void update_barrel_animation(t_barrel *tonneau)
{
    tonneau->frame = (tonneau->frame + 1) % TOTAL_FRAMES;
}


// Appelé à chaque frame par votre boucle de jeu
void game_update(t_barrel *tonneaux, int window_width, int start_y)
{
    for (int i = 0; i < NUM_TONNEAUX; i++) {
        update_barrel_position(&tonneaux[i], window_width, start_y);
        //update_barrel_animation(&tonneaux[i], window_width, start_y);
        // Ici, ajoutez le code pour dessiner le tonneau en utilisant MLX42
        // mlx_draw_texture(tonneau_texture[tonneaux[i].frame], tonneaux[i].x, tonneaux[i].y);
    }
}


// Dans votre fonction principale ou initialisation du jeu
t_barrel tonneaux[NUM_TONNEAUX];
//initialiser_tonneaux(tonneaux, window_width, start_y); // window_width et start_y doivent être définis
// Initialiser les tonneaux ici...
