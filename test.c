/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2024/01/26 14:30:13 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "src/get_next_line.h"
#include "src/so_long.h"

void	initialize_textures(mlx_t *mlx, t_all *all)
{
	int	i;

	i = 0;
	all->textinf[0].texture = mlx_load_png("png/rock32.png");
	all->textinf[1].texture = mlx_load_png("png/back32.png");
	all->textinf[2].texture = mlx_load_png("png/banana32.png");
	all->textinf[3].texture = mlx_load_png("png/doorclose32.png");
	all->textinf[4].texture = mlx_load_png("png/kong32.png");
	all->textinf[5].texture = mlx_load_png("png/ladder32.png");
	all->textinf[6].texture = mlx_load_png("png/bloc32.png");
	all->textinf[7].texture = mlx_load_png("png/fire32.png");
	all->textinf[8].texture = mlx_load_png("png/1barrel32.png");
	all->textinf[9].texture = mlx_load_png("png/2barrel32.png");
	all->textinf[10].texture = mlx_load_png("png/3barrel32.png");
	all->textinf[11].texture = mlx_load_png("png/4barrel32.png");
	all->textinf[12].texture = mlx_load_png("png/reversekong32.png");
	all->textinf[13].texture = mlx_load_png("png/dooropen32.png");
	all->textinf[14].texture = mlx_load_png("png/blast32.png");
	while (i < 15)
	{
		all->textinf[i].img = mlx_texture_to_image(mlx,
				all->textinf[i].texture);
		mlx_delete_texture(all->textinf[i].texture);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_all	all;
	int fd;

	all.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "So_Long", true);
	if (!all.mlx)
		return (1);
	(void)ac;
    all.move.nb_move = 0;
	initialize_textures(all.mlx, &all);
	count_line(&all, av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	aff_map(fd, &all);
	is_map_valid(&all);
	close(fd);
	mlx_loop_hook(all.mlx, ft_hook, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}
