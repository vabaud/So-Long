/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:17:09 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/11 07:42:13 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	aff_back(int y, t_all *all)
{
	int	x;

	x = 0;
	while (all->mapy.mapp[y][x] != '\0')
	{
		if (all->mapy.mapp[y][x] == '1')
			mlx_image_to_window(all->mlx, all->textinf[0].img, x * TS, y * TS);
		if (all->mapy.mapp[y][x] != '1')
			mlx_image_to_window(all->mlx, all->textinf[1].img, x * TS, y * TS);
		if (all->mapy.mapp[y][x] == 'E')
		{
			mlx_image_to_window(all->mlx, all->textinf[3].img, x * TS, y * TS);
			mlx_image_to_window(all->mlx, all->textinf[13].img, x * TS, y * TS);
			all->textinf[13].img->enabled = false;
		}
		if (all->mapy.mapp[y][x] == 'Y')
			mlx_image_to_window(all->mlx, all->textinf[5].img, x * TS, y * TS);
		if (all->mapy.mapp[y][x] == 'W')
			mlx_image_to_window(all->mlx, all->textinf[6].img, x * TS, y * TS);
		if (all->mapy.mapp[y][x] == 'F')
			mlx_image_to_window(all->mlx, all->textinf[7].img, x * TS, y * TS);
		x++;
	}
}

void	aff_front(int y, t_all *all)
{
	int	x;

	x = 0;
	while (all->mapy.mapp[y][x] != '\0')
	{
		if (all->mapy.mapp[y][x] == 'C')
			mlx_image_to_window(all->mlx, all->textinf[2].img, x * TS, y * TS);
		if (all->mapy.mapp[y][x] == 'P')
		{
			mlx_image_to_window(all->mlx, all->textinf[4].img, x * TS, y * TS);
			mlx_image_to_window(all->mlx, all->textinf[12].img, x * TS, y * TS);
			all->textinf[12].img->enabled = false;
		}
		if (all->mapy.mapp[y][x] == '2')
		{
			mlx_image_to_window(all->mlx, all->textinf[8].img, x * TS, y * TS);
			mlx_image_to_window(all->mlx, all->textinf[9].img, x * TS, y * TS);
			mlx_image_to_window(all->mlx, all->textinf[10].img, x * TS, y * TS);
			mlx_image_to_window(all->mlx, all->textinf[11].img, x * TS, y * TS);
			all->textinf[9].img->enabled = false;
			all->textinf[10].img->enabled = false;
			all->textinf[11].img->enabled = false;
		}
		x++;
	}
}

void	aff_map(int fd, t_all *all)
{
	int	y;

	all->mapy.nb_c = 0;
    all->mapy.nb_e = 0;
    all->mapy.nb_p = 0;
    all->mapy.nb_other = 0;
	y = 0;
	all->mapy.mapp = malloc(100 * sizeof(char *));
	while (y < all->mapy.nb_l)
	{
		all->mapy.mapp[y] = get_next_line(fd);
		aff_back(y, all);
		y++;
	}
	all->mapy.mapp[y] = NULL;
	close(fd);
	all->mapy.max_x = ft_strlen(all->mapy.mapp[1]);
	y = 0;
	while (y < all->mapy.nb_l)
	{
		aff_front(y, all);
		y++;
	}
}
