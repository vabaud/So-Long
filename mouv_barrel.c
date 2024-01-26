/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_barrel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:42:43 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/26 12:27:57 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"

void	mouv_right(t_all *all)
{
	int	i;

	all->textinf[8].img->instances[0].x += 8;
	all->textinf[9].img->instances[0].x += 8;
	all->textinf[10].img->instances[0].x += 8;
	all->textinf[11].img->instances[0].x += 8;
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

	all->textinf[8].img->instances[0].x -= 8;
	all->textinf[9].img->instances[0].x -= 8;
	all->textinf[10].img->instances[0].x -= 8;
	all->textinf[11].img->instances[0].x -= 8;
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

void	mouv_down(t_all *all)
{
	int	i;

	all->textinf[8].img->instances[0].y += 8;
	all->textinf[9].img->instances[0].y += 8;
	all->textinf[10].img->instances[0].y += 8;
	all->textinf[11].img->instances[0].y += 8;
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

void	mouv_barrel(t_all *all)
{
	static unsigned long long	last_move_time = 0;
	unsigned long long			current_time;
	static int					sens = 1;

	current_time = getCurrentTimeInMilliseconds();
	if (current_time - last_move_time >= all->move.vit)
	{
		if (is_pos_valid(all->textinf[8].img->instances[0].x + 32,
				all->textinf[8].img->instances[0].y, all) && sens == 1)
			mouv_right(all);
		else if (is_pos_valid(all->textinf[8].img->instances[0].x,
				all->textinf[8].img->instances[0].y + 32, all)
			&& ((all->textinf[8].img->instances[0].x + 32) % 32 == 0))
			mouv_down(all);
		else if (is_pos_valid(all->textinf[8].img->instances[0].x - 8,
				all->textinf[8].img->instances[0].y, all))
		{
			mouv_left(all);
			sens = 0;
		}
		if (all->move.vit > 50)
			all->move.vit--;
		last_move_time = current_time;
	}
}
