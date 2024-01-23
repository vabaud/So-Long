/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:17:09 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/23 19:49:31 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"

void	count_line(t_all *all, char *argv)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	all->mapy.nb_l = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		all->mapy.nb_l++;
	}
	close(fd);
}

void aff_back(int y, t_all *all)
{
    int x;
    
    x = 0;
    while (all->mapy.mapp[y][x] != '\0')
    {
        if (all->mapy.mapp[y][x] == '1' ) // texture1 = mur
            mlx_image_to_window(all->mlx, all->textInf[0].img, x * TILE_SIZE, y * TILE_SIZE);
        if (all->mapy.mapp[y][x] == '0' || all->mapy.mapp[y][x] == 'C' || all->mapy.mapp[y][x] == 'P' || all->mapy.mapp[y][x] == 'Y' || all->mapy.mapp[y][x] == 'W' || all->mapy.mapp[y][x] == 'F' 
		|| all->mapy.mapp[y][x] == '2')
            mlx_image_to_window(all->mlx, all->textInf[1].img, x * TILE_SIZE, y * TILE_SIZE);
        if (all->mapy.mapp[y][x] == 'E' ) // texture3 = sortie
        {
            mlx_image_to_window(all->mlx, all->textInf[3].img, x * TILE_SIZE, y * TILE_SIZE);
            mlx_image_to_window(all->mlx, all->textInf[13].img, x * TILE_SIZE, y * TILE_SIZE);
			all->textInf[13].img->enabled = false;
        }
        if (all->mapy.mapp[y][x] == 'Y' ) // texture3 = echelle
            mlx_image_to_window(all->mlx, all->textInf[5].img, x * TILE_SIZE, y * TILE_SIZE);
        if (all->mapy.mapp[y][x] == 'W' ) // texture6 = support
            mlx_image_to_window(all->mlx, all->textInf[6].img, x * TILE_SIZE, y * TILE_SIZE);
        if (all->mapy.mapp[y][x] == 'F' ) // texture = feux
            mlx_image_to_window(all->mlx, all->textInf[7].img, x * TILE_SIZE, y * TILE_SIZE);
        x++;
    }
}

void aff_front(int y, t_all *all)
{
    int x;

    x = 0;
    while (all->mapy.mapp[y][x] != '\0')
    {
        if (all->mapy.mapp[y][x] == 'C' ) // texture2 = collectable
            mlx_image_to_window(all->mlx, all->textInf[2].img, x * TILE_SIZE, y * TILE_SIZE);
        if (all->mapy.mapp[y][x] == 'P' ) // texture4 = perso
        {
            mlx_image_to_window(all->mlx, all->textInf[4].img, x * TILE_SIZE, y * TILE_SIZE);
            mlx_image_to_window(all->mlx, all->textInf[12].img, x * TILE_SIZE, y * TILE_SIZE);
            all->textInf[12].img->enabled = false;
        }
        if (all->mapy.mapp[y][x] == '2' ) // texture = barrel1
        {
			mlx_image_to_window(all->mlx, all->textInf[8].img, x * TILE_SIZE, y * TILE_SIZE);
            mlx_image_to_window(all->mlx, all->textInf[9].img, x * TILE_SIZE, y * TILE_SIZE);
            mlx_image_to_window(all->mlx, all->textInf[10].img, x * TILE_SIZE, y * TILE_SIZE);
            mlx_image_to_window(all->mlx, all->textInf[11].img, x * TILE_SIZE, y * TILE_SIZE);
            all->textInf[9].img->enabled = false;
            all->textInf[10].img->enabled = false;
            all->textInf[11].img->enabled = false;
        }
        x++;
    }
}

void aff_map(int fd, t_all *all)
{
    all->move.vit = 200;
    all->mapy.nb_c = 0;
    int y = 0;
    all->mapy.mapp = malloc(100 * sizeof(char *));
    while (y < all->mapy.nb_l)
    {
        all->mapy.mapp[y] = get_next_line(fd);
        aff_back(y, all);
        y++;
    }
    close(fd);
    all->mapy.maxX = ft_strlen(all->mapy.mapp[1]);
    y = 0;
    while (y < all->mapy.nb_l)
    {
        aff_front(y, all);
        y++;
    }
}
