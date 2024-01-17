/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_barrel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:42:43 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/17 20:30:54 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"

#define NUM_TONNEAUX 4
#define VITESSE 1
#define TOTAL_FRAMES 4
// #define window_width 0
//#define start_y 0

void mouv_right()
{
    textureInfoArray[8].img->instances[0].x += 8;
    textureInfoArray[9].img->instances[0].x += 8;
    textureInfoArray[10].img->instances[0].x += 8;
    textureInfoArray[11].img->instances[0].x += 8;
    if (textureInfoArray[8].img->enabled == true)
    {
        textureInfoArray[8].img->enabled = false;
        textureInfoArray[9].img->enabled = true;
        textureInfoArray[10].img->enabled = false;
        textureInfoArray[11].img->enabled = false;
        mapy.vit /= 1.005;
    }
    else if (textureInfoArray[9].img->enabled == true)
    {
        textureInfoArray[9].img->enabled = false;
        textureInfoArray[8].img->enabled = false;
        textureInfoArray[10].img->enabled = true;
        textureInfoArray[11].img->enabled = false;
        mapy.vit /= 1.005;
    }
    else if (textureInfoArray[10].img->enabled == true)
    {
        textureInfoArray[10].img->enabled = false;
        textureInfoArray[9].img->enabled = false;
        textureInfoArray[8].img->enabled = false;
        textureInfoArray[11].img->enabled = true;
        mapy.vit /= 1.005;
    }
    else if (textureInfoArray[11].img->enabled == true)
    {
        textureInfoArray[11].img->enabled = false;
        textureInfoArray[9].img->enabled = false;
        textureInfoArray[10].img->enabled = false;
        textureInfoArray[8].img->enabled = true;
        mapy.vit /= 1.005;
    }
}
void mouv_left()
{
    textureInfoArray[8].img->instances[0].x -= 8;
    textureInfoArray[9].img->instances[0].x -= 8;
    textureInfoArray[10].img->instances[0].x -= 8;
    textureInfoArray[11].img->instances[0].x -= 8;
    if (textureInfoArray[8].img->enabled == true)
    {
        textureInfoArray[8].img->enabled = false;
        textureInfoArray[9].img->enabled = false;
        textureInfoArray[10].img->enabled = false;
        textureInfoArray[11].img->enabled = true;
        mapy.vit /= 1.005;
    }
    else if (textureInfoArray[11].img->enabled == true)
    {
        textureInfoArray[9].img->enabled = false;
        textureInfoArray[8].img->enabled = false;
        textureInfoArray[10].img->enabled = true;
        textureInfoArray[11].img->enabled = false;
        mapy.vit /= 1.005;
    }
    else if (textureInfoArray[10].img->enabled == true)
    {
        textureInfoArray[10].img->enabled = false;
        textureInfoArray[9].img->enabled = true;
        textureInfoArray[8].img->enabled = false;
        textureInfoArray[11].img->enabled = false;
        mapy.vit /= 1.005;
    }
    else if (textureInfoArray[9].img->enabled == true)
    {
        textureInfoArray[11].img->enabled = false;
        textureInfoArray[9].img->enabled = false;
        textureInfoArray[10].img->enabled = false;
        textureInfoArray[8].img->enabled = true;
        mapy.vit /= 1.005;
    }
}
void mouv_down()
{
    textureInfoArray[8].img->instances[0].y += 8;
    textureInfoArray[9].img->instances[0].y += 8;
    textureInfoArray[10].img->instances[0].y += 8;
    textureInfoArray[11].img->instances[0].y += 8;
    if (textureInfoArray[8].img->enabled == true)
    {
        textureInfoArray[8].img->enabled = false;
        textureInfoArray[9].img->enabled = false;
        textureInfoArray[10].img->enabled = false;
        textureInfoArray[11].img->enabled = true;
        mapy.vit /= 1.005;
    }
    else if (textureInfoArray[11].img->enabled == true)
    {
        textureInfoArray[9].img->enabled = false;
        textureInfoArray[8].img->enabled = false;
        textureInfoArray[10].img->enabled = true;
        textureInfoArray[11].img->enabled = false;
        mapy.vit /= 1.005;
    }
    else if (textureInfoArray[10].img->enabled == true)
    {
        textureInfoArray[10].img->enabled = false;
        textureInfoArray[9].img->enabled = true;
        textureInfoArray[8].img->enabled = false;
        textureInfoArray[11].img->enabled = false;
        mapy.vit /= 1.005;
    }
    else if (textureInfoArray[9].img->enabled == true)
    {
        textureInfoArray[11].img->enabled = false;
        textureInfoArray[9].img->enabled = false;
        textureInfoArray[10].img->enabled = false;
        textureInfoArray[8].img->enabled = true;
        mapy.vit /= 1.005;
    }
}


void mouvBarrel(void)
{
    static unsigned long long	lastMoveTime = 0;
    unsigned long long			currentTime;
	currentTime = getCurrentTimeInMilliseconds();
    static int sens = 1;
    
    if (currentTime - lastMoveTime >= mapy.vit)
    {
        if (isPositionValid(textureInfoArray[8].img->instances[0].x + 32, textureInfoArray[8].img->instances[0].y) && sens == 1)
            mouv_right();
        else if (isPositionValid(textureInfoArray[8].img->instances[0].x, textureInfoArray[8].img->instances[0].y + 32))
        {
            mouv_down();
            mapy.vit = 100;
        }
        else if (isPositionValid(textureInfoArray[8].img->instances[0].x - 8, textureInfoArray[8].img->instances[0].y))
        {
            mouv_left();
            sens = 0;
        }
        lastMoveTime = currentTime;
    }
}