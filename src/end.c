/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:05:23 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/02 19:08:08 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/so_long.h"

// void	frame_1(void *param, int newX, int newY)
// {
// 	t_all	*all;

// 	all = param;
// 	newX = all->textinf[4].img->instances->x;
// 	newY = all->textinf[4].img->instances->y;
// 	mlx_image_to_window(all->mlx, all->textinf[14].img, newX, newY);
// }

// void	frame_2(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[15].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[15].img, x, y);
// }

// void	frame_3(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[16].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[16].img, x, y);
// }

// void	frame_4(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[17].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[17].img, x, y);
// }

// void	frame_5(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[18].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[18].img, x, y);
// }

// void	frame_6(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[19].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[19].img, x, y);
// }

// void	frame_7(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[20].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[20].img, x, y);
// }

// void	frame_8(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[21].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[21].img, x, y);
// }

// void	frame_9(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[22].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[22].img, x, y);
// }

// void	frame_10(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[23].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[23].img, x, y);
// }

// void	frame_11(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[24].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[24].img, x, y);
// }

// void	frame_12(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[25].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[25].img, x, y);
// }

// void	frame_13(void *param)
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[26].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[26].img, x, y);
// }

// void	frame_14(void *param) // game over
// {
// 	t_all		*all;
// 	int			x;
// 	int			y;

// 	all = param;
// 	x = 0;
// 	y = 0;
// 	mlx_resize_image(all->textinf[27].img, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_image_to_window(all->mlx, all->textinf[27].img, x, y);
// }

// void (*frame_functions[])(void *) = {frame_1, frame_2, frame_3, 
//frame_4, frame_5, frame_6, frame_7, frame_8, frame_9, frame_10, 
//frame_11, frame_12, frame_13, frame_14};

// void animate_next_frame(void *param)
// {
// 	static int frame = 0;
// 	static clock_t last_update = 0;
// 	t_all *all = param;
// 	clock_t now = clock();
// 	int									newX;
// 	int									newY;
// 	newX = all->textinf[4].img->instances->x;
// 	newY = all->textinf[4].img->instances->y;

// 	if ((double)(now - last_update) / CLOCKS_PER_SEC > 0.18)
// 	{
// 		if (all->textinf[8].img->instances->x ==
//			all->textinf[4].img->instances->x
// 			&& all->textinf[8].img->instances->y ==
//			all->textinf[4].img->instances->y)
// 		{
// 			frame_functions[frame](all->mlx);
// 			frame = (frame + 1) % (sizeof(frame_functions)
//			/ sizeof(frame_functions[0]));
// 		}
// 		if (all->mapy.mapp[newY / 32][newX / 32] == 'E'
// 		&& (all->textinf[2].img->count == all->mapy.nb_c))
// 		{
// 			frame_functions[frame](all->mlx);
// 			frame = (frame + 1) % (sizeof(frame_functions)
//			/ sizeof(frame_functions[0]));
// 		}
// 		last_update = now;
// 	}
// }
