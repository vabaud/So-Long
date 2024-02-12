/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_barrel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:42:43 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/12 11:43:18 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	mouv_right(t_all *all)
{
	int	i;

	usleep(80000);
	all->textinf[5].img->instances[0].x += 32;
	all->textinf[6].img->instances[0].x += 32;
	all->textinf[7].img->instances[0].x += 32;
	all->textinf[8].img->instances[0].x += 32;
	i = 0;
	if (all->textinf[5].img->enabled == true)
		i = 6;
	else if (all->textinf[6].img->enabled == true)
		i = 7;
	else if (all->textinf[7].img->enabled == true)
		i = 8;
	else if (all->textinf[8].img->enabled == true)
		i = 5;
	all->textinf[5].img->enabled = false;
	all->textinf[6].img->enabled = false;
	all->textinf[7].img->enabled = false;
	all->textinf[8].img->enabled = false;
	all->textinf[i].img->enabled = true;
}

void	mouv_left(t_all *all)
{
	int	i;

	usleep(80000);
	all->textinf[5].img->instances[0].x -= 32;
	all->textinf[6].img->instances[0].x -= 32;
	all->textinf[7].img->instances[0].x -= 32;
	all->textinf[8].img->instances[0].x -= 32;
	i = 0;
	if (all->textinf[5].img->enabled == true)
		i = 8;
	else if (all->textinf[8].img->enabled == true)
		i = 7;
	else if (all->textinf[7].img->enabled == true)
		i = 6;
	else if (all->textinf[6].img->enabled == true)
		i = 5;
	all->textinf[5].img->enabled = false;
	all->textinf[6].img->enabled = false;
	all->textinf[7].img->enabled = false;
	all->textinf[8].img->enabled = false;
	all->textinf[i].img->enabled = true;
}

void	mouv_barrel(t_all *all)
{
	static int	sens = 1;

	if (all->textinf[4].img->instances[0].x
		== all->textinf[5].img->instances[0].x
		&& all->textinf[4].img->instances[0].y
		== all->textinf[5].img->instances[0].y)
		mlx_close_window(all->mlx);
	if (!is_pos_valid(all->textinf[5].img->instances[0].x - 8,
			all->textinf[5].img->instances[0].y, all))
		sens = 1;
	if (is_pos_valid(all->textinf[5].img->instances[0].x + 32,
			all->textinf[5].img->instances[0].y, all) && sens == 1)
		mouv_right(all);
	else if (is_pos_valid(all->textinf[5].img->instances[0].x - 8,
			all->textinf[5].img->instances[0].y, all))
	{
		mouv_left(all);
		sens = 0;
	}
}
