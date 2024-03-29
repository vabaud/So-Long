/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:52 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/12 11:00:50 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	initialize_textures(mlx_t *mlx, t_all *all)
{
	int	i;

	i = 0;
	all->textinf[0].texture = mlx_load_png("png/rock32.png");
	all->textinf[1].texture = mlx_load_png("png/back32.png");
	all->textinf[2].texture = mlx_load_png("png/banana32.png");
	all->textinf[3].texture = mlx_load_png("png/doorclose32.png");
	all->textinf[4].texture = mlx_load_png("png/kong32.png");
	all->textinf[5].texture = mlx_load_png("png/1barrel32.png");
	all->textinf[6].texture = mlx_load_png("png/2barrel32.png");
	all->textinf[7].texture = mlx_load_png("png/3barrel32.png");
	all->textinf[8].texture = mlx_load_png("png/4barrel32.png");
	all->textinf[9].texture = mlx_load_png("png/reversekong32.png");
	all->textinf[10].texture = mlx_load_png("png/dooropen32.png");
	while (i < 11)
	{
		all->textinf[i].img = mlx_texture_to_image(mlx,
				all->textinf[i].texture);
		mlx_delete_texture(all->textinf[i].texture);
		i++;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	error(int ac, t_all *all)
{
	if (ac != 2)
	{
		write(1, "Erreur\n", 7);
		exit(1);
	}
	all->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "So_Long", true);
	if (!all->mlx)
		exit(1);
}

void	move(t_all *all, int *newX, int *newY)
{
	int	x;
	int	y;

	x = *newX;
	y = *newY;
	if (is_pos_valid(x, y, all))
	{
		all->move.nb_move++;
		printf("Nombre de mouvements : %d\n", all->move.nb_move);
	}
}

int	main(int ac, char **av)
{
	t_all	all;
	int		fd;

	error(ac, &all);
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
	free_tab(all.mapy.mapp);
	return (0);
}
