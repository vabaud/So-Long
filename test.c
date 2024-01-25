/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/25 21:50:11 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"

void initializeTextures(mlx_t* mlx, t_all *all)
{
    int i = 0;
    all->textInf[0].texture = mlx_load_png("png/rock32.png");
    all->textInf[1].texture = mlx_load_png("png/back32.png");
    all->textInf[2].texture = mlx_load_png("png/banana32.png");
    all->textInf[3].texture = mlx_load_png("png/doorclose32.png");
    all->textInf[4].texture = mlx_load_png("png/kong32.png");
    all->textInf[5].texture = mlx_load_png("png/ladder32.png");
    all->textInf[6].texture = mlx_load_png("png/bloc32.png");
    all->textInf[7].texture = mlx_load_png("png/fire32.png");
    all->textInf[8].texture = mlx_load_png("png/1barrel32.png");
    all->textInf[9].texture = mlx_load_png("png/2barrel32.png");
    all->textInf[10].texture = mlx_load_png("png/3barrel32.png");
    all->textInf[11].texture = mlx_load_png("png/4barrel32.png");
    all->textInf[12].texture = mlx_load_png("png/reversekong32.png");
    all->textInf[13].texture = mlx_load_png("png/dooropen32.png");
    all->textInf[14].texture = mlx_load_png("png/blast32.png");

	while (i < 15)
	{
		all->textInf[i].img = mlx_texture_to_image(mlx, all->textInf[i].texture);
		mlx_delete_texture(all->textInf[i].texture);
		i++;
	}
}


int main(int ac, char **av)  
{
    t_all all;

    all.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "So_Long", true);
    if (!all.mlx)
        return 1;
    (void)ac;
    initializeTextures(all.mlx, &all);
    count_line(&all, av[1]);
    int fd = open(av[1], O_RDONLY);  // Ouvre le fichier en lecture seule

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
    }
    aff_map(fd, &all);
    isMapValid(&all);
    close(fd);
    // Affichage de la carte
    mlx_loop_hook(all.mlx, ft_hook, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);

	return 0;
}
