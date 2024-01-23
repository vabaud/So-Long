/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_barrel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:42:43 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/23 16:07:28 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"

void	mouv_right(t_all *all)
{
	int	i;

	all->textInf[8].img->instances[0].x += 8;
	all->textInf[9].img->instances[0].x += 8;
	all->textInf[10].img->instances[0].x += 8;
	all->textInf[11].img->instances[0].x += 8;
	i = 0;
	if (all->textInf[8].img->enabled == true)
		i = 9;
	else if (all->textInf[9].img->enabled == true)
		i = 10;
	else if (all->textInf[10].img->enabled == true)
		i = 11;
	else if (all->textInf[11].img->enabled == true)
		i = 8;
	all->textInf[8].img->enabled = false;
	all->textInf[9].img->enabled = false;
	all->textInf[10].img->enabled = false;
	all->textInf[11].img->enabled = false;
	all->textInf[i].img->enabled = true;
}

void	mouv_left(t_all *all)
{
	int	i;

	all->textInf[8].img->instances[0].x -= 8;
	all->textInf[9].img->instances[0].x -= 8;
	all->textInf[10].img->instances[0].x -= 8;
	all->textInf[11].img->instances[0].x -= 8;
	i = 0;
	if (all->textInf[8].img->enabled == true)
		i = 11;
	else if (all->textInf[11].img->enabled == true)
		i = 10;
	else if (all->textInf[10].img->enabled == true)
		i = 9;
	else if (all->textInf[9].img->enabled == true)
		i = 8;
	all->textInf[8].img->enabled = false;
	all->textInf[9].img->enabled = false;
	all->textInf[10].img->enabled = false;
	all->textInf[11].img->enabled = false;
	all->textInf[i].img->enabled = true;
}

void	mouv_down(t_all *all)
{
	int	i;

	all->textInf[8].img->instances[0].y += 8;
	all->textInf[9].img->instances[0].y += 8;
	all->textInf[10].img->instances[0].y += 8;
	all->textInf[11].img->instances[0].y += 8;
	i = 0;
	if (all->textInf[8].img->enabled == true)
		i = 9;
	else if (all->textInf[9].img->enabled == true)
		i = 10;
	else if (all->textInf[10].img->enabled == true)
		i = 11;
	else if (all->textInf[11].img->enabled == true)
		i = 8;
	all->textInf[8].img->enabled = false;
	all->textInf[9].img->enabled = false;
	all->textInf[10].img->enabled = false;
	all->textInf[11].img->enabled = false;
	all->textInf[i].img->enabled = true;
}

void	mouvBarrel(t_all *all)
{
	static unsigned long long	lastMoveTime = 0;
	unsigned long long			currentTime;
	static int					sens = 1;

	currentTime = getCurrentTimeInMilliseconds();
	if (currentTime - lastMoveTime >= all->move.vit)
	{
		if (isPositionValid(all->textInf[8].img->instances[0].x + 32,
				all->textInf[8].img->instances[0].y, all) && sens == 1)
			mouv_right(all);
		else if (isPositionValid(all->textInf[8].img->instances[0].x,
				all->textInf[8].img->instances[0].y + 32, all)
			&& ((all->textInf[8].img->instances[0].x + 32) % 32 == 0))
			mouv_down(all);
		else if (isPositionValid(all->textInf[8].img->instances[0].x - 8,
				all->textInf[8].img->instances[0].y, all))
		{
			mouv_left(all);
			sens = 0;
		}
        if (all->move.vit > 50)
            all->move.vit--;
		lastMoveTime = currentTime;
	}
}
