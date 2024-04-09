/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_barrel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:42:43 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/09 20:51:02 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	verif_barrel(t_all *all, char name)
{
	size_t	i;

	i = -1;
	while (++i < all->textinf[5].img->count)
	{
		if (all->textinf[4].img->instances[0].y
			== all->textinf[5].img->instances[i].y)
		{
			if (all->textinf[4].img->instances[0].x
				== all->textinf[5].img->instances[i].x)
				mlx_close_window(all->mlx);
			if (name == 'r')
			{
				if (all->textinf[4].img->instances[0].x
					== all->textinf[5].img->instances[i].x - 32)
					mlx_close_window(all->mlx);
			}
			else if (name == 'l')
			{
				if (all->textinf[4].img->instances[0].x
					== all->textinf[5].img->instances[i].x + 32)
					mlx_close_window(all->mlx);
			}
		}
	}
}

void	mouv_right(t_all *all, size_t j)
{
	int	i;

	all->textinf[5].img->instances[j].x += 32;
	all->textinf[6].img->instances[j].x += 32;
	all->textinf[7].img->instances[j].x += 32;
	all->textinf[8].img->instances[j].x += 32;
	i = 0;
	if (all->textinf[5].img->instances[j].enabled == true)
		i = 6;
	else if (all->textinf[6].img->instances[j].enabled == true)
		i = 7;
	else if (all->textinf[7].img->instances[j].enabled == true)
		i = 8;
	else if (all->textinf[8].img->instances[j].enabled == true)
		i = 5;
	all->textinf[5].img->instances[j].enabled = false;
	all->textinf[6].img->instances[j].enabled = false;
	all->textinf[7].img->instances[j].enabled = false;
	all->textinf[8].img->instances[j].enabled = false;
	all->textinf[i].img->instances[j].enabled = true;
	verif_barrel(all, 'r');
}

void	mouv_left(t_all *all, size_t j)
{
	int	i;

	all->textinf[5].img->instances[j].x -= 32;
	all->textinf[6].img->instances[j].x -= 32;
	all->textinf[7].img->instances[j].x -= 32;
	all->textinf[8].img->instances[j].x -= 32;
	i = 0;
	if (all->textinf[5].img->instances[j].enabled == true)
		i = 8;
	else if (all->textinf[8].img->instances[j].enabled == true)
		i = 7;
	else if (all->textinf[7].img->instances[j].enabled == true)
		i = 6;
	else if (all->textinf[6].img->instances[j].enabled == true)
		i = 5;
	all->textinf[5].img->instances[j].enabled = false;
	all->textinf[6].img->instances[j].enabled = false;
	all->textinf[7].img->instances[j].enabled = false;
	all->textinf[8].img->instances[j].enabled = false;
	all->textinf[i].img->instances[j].enabled = true;
	verif_barrel(all, 'l');
}

void	mouv_barrel(t_all *all)
{
	static int	sens[500];
	size_t		i;

	i = 0;
	while (i < all->textinf[5].img->count)
	{
		if (!is_pos_valid(all->textinf[5].img->instances[i].x - 8,
				all->textinf[5].img->instances[i].y, all))
			sens[i] = 1;
		if (is_pos_valid(all->textinf[5].img->instances[i].x + 32,
				all->textinf[5].img->instances[i].y, all) && sens[i] == 1)
			mouv_right(all, i);
		else if (is_pos_valid(all->textinf[5].img->instances[i].x - 8,
				all->textinf[5].img->instances[i].y, all))
		{
			mouv_left(all, i);
			sens[i] = 0;
		}
		i++;
	}
}
