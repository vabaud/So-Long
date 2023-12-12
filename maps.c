/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:17:09 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/12 15:20:35 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void render_callback(void* param) {
    mlx_t* mlx = (mlx_t*)param;
    mlx_clear(mlx);

    // Dessiner la carte
    int fd = open("maps/maps.ber", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    y = 0;
    while ((map = get_next_line(fd)) != NULL) {
        render_map(mlx, map);
        free(map);
    }
    close(fd);

    // Dessiner le personnage à sa position actuelle
    mlx_draw_texture(mlx, character.texture, character.x, character.y, character.width, character.height);
}
