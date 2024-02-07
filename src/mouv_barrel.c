/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_barrel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:42:43 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/02 17:37:46 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	mouv_right(t_all *all)
{
	int	i;

	usleep(80000);
	all->textinf[8].img->instances[0].x += 32;
	all->textinf[9].img->instances[0].x += 32;
	all->textinf[10].img->instances[0].x += 32;
	all->textinf[11].img->instances[0].x += 32;
	i = 0;
	if (all->textinf[8].img->enabled == true)
		i = 9;
	else if (all->textinf[9].img->enabled == true)
		i = 10;
	else if (all->textinf[10].img->enabled == true)
		i = 11;
	else if (all->textinf[11].img->enabled == true)
		i = 8;
	all->textinf[8].img->enabled = false;
	all->textinf[9].img->enabled = false;
	all->textinf[10].img->enabled = false;
	all->textinf[11].img->enabled = false;
	all->textinf[i].img->enabled = true;
}

void	mouv_left(t_all *all)
{
	int	i;

	usleep(80000);
	all->textinf[8].img->instances[0].x -= 32;
	all->textinf[9].img->instances[0].x -= 32;
	all->textinf[10].img->instances[0].x -= 32;
	all->textinf[11].img->instances[0].x -= 32;
	i = 0;
	if (all->textinf[8].img->enabled == true)
		i = 11;
	else if (all->textinf[11].img->enabled == true)
		i = 10;
	else if (all->textinf[10].img->enabled == true)
		i = 9;
	else if (all->textinf[9].img->enabled == true)
		i = 8;
	all->textinf[8].img->enabled = false;
	all->textinf[9].img->enabled = false;
	all->textinf[10].img->enabled = false;
	all->textinf[11].img->enabled = false;
	all->textinf[i].img->enabled = true;
}

void	mouv_barrel(t_all *all)
{
	static int					sens = 1;

	if (!is_pos_valid(all->textinf[8].img->instances[0].x - 8,
			all->textinf[8].img->instances[0].y, all))
		sens = 1;
	usleep(50000);
	if (is_pos_valid(all->textinf[8].img->instances[0].x + 32,
			all->textinf[8].img->instances[0].y, all) && sens == 1)
		mouv_right(all);
	else if (is_pos_valid(all->textinf[8].img->instances[0].x - 8,
			all->textinf[8].img->instances[0].y, all))
	{
		mouv_left(all);
		sens = 0;
	}
	if (all->move.vit > 50)
		all->move.vit--;
}