/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:56:16 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/23 16:31:20 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"
//#include "mouv_perso.c"

void frame_1(void *param)
{
    t_all *all = param;
    int newX = all->textInf[4].img->instances->x;
    int newY = all->textInf[4].img->instances->y;

    mlx_image_to_window(all->mlx, all->textInf[14].img, newX, newY);
}

void frame_2(void *param)
{
    t_all *all = param;
    int x = 0;
    int y = 0;

    mlx_resize_image(all->textInf[15].img, WIN_WIDTH, WIN_HEIGHT);
    mlx_image_to_window(all->mlx, all->textInf[15].img, x, y);
}

void	frame_3(void *param)
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[16].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[16].img, x, y);
}

void	frame_4(void *param)
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[17].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[17].img, x, y);
}

void	frame_5(void *param)
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[18].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[18].img, x, y);
}

void	frame_6(void *param)
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[19].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[19].img, x, y);
}

void	frame_7(void *param)
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[20].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[20].img, x, y);
}

void	frame_8(void *param)
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[21].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[21].img, x, y);
}

void	frame_9(void *param)
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[22].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[22].img, x, y);
}

void	frame_10(void *param)
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[23].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[23].img, x, y);
}

void	frame_11(void *param)
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[24].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[24].img, x, y);
}

void	frame_12(void *param)
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[25].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[25].img, x, y);
}

void	frame_13(void *param)
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[26].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[26].img, x, y);
}

void	frame_14(void *param) // game over
{
	t_all *all = param;
	int x = 0;
	int y = 0;

	mlx_resize_image(all->textInf[27].img, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(all->mlx, all->textInf[27].img, x, y);
}

// void	frame_15(void *param)
// {
// 	mlx_close_window(param);
// }

void (*frame_functions[])(void *) = {frame_1, frame_2, frame_3, frame_4, frame_5, frame_6, frame_7, frame_8, frame_9, frame_10, frame_11, frame_12, frame_13, frame_14};

#include <time.h>

void animate_next_frame(void *param)
{
    static int frame = 0;
    static clock_t last_update = 0;
    t_all *all = param;
    clock_t now = clock();
	int							newX;
	int							newY;
	newX = all->textInf[4].img->instances->x;
	newY = all->textInf[4].img->instances->y;

    if ((double)(now - last_update) / CLOCKS_PER_SEC > 0.18)  // 0.5 seconds delay
    {
        if (all->textInf[8].img->instances->x == all->textInf[4].img->instances->x 
        && all->textInf[8].img->instances->y == all->textInf[4].img->instances->y)
        {
		    frame_functions[frame](all->mlx);
		    frame = (frame + 1) % (sizeof(frame_functions) / sizeof(frame_functions[0]));
        }
		if (all->mapy.mapp[newY / 32][newX / 32] == 'E'
		&& (all->textInf[2].img->count == all->mapy.nb_c))
		{
		    frame_functions[frame](all->mlx);
		    frame = (frame + 1) % (sizeof(frame_functions) / sizeof(frame_functions[0]));
		}
        last_update = now;
    }
}
