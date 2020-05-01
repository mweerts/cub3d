/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:39:33 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/01 19:39:05 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		setup_mlx(t_game *game)
{
	if (!(game->mlx_ptr = mlx_init()))
		error("Erreur lors de l'initialisation de la minilibx.");
	if (!load_image(game->map.tex_no, &(game->tex_no), game->mlx_ptr))
		error("Erreur lors du chargement de la texture nord.");
	if (!load_image(game->map.tex_so, &(game->tex_so), game->mlx_ptr))
		error("Erreur lors du chargement de la texture sud.");
	if (!load_image(game->map.tex_ea, &(game->tex_ea), game->mlx_ptr))
		error("Erreur lors du chargement de la texture est.");
	if (!load_image(game->map.tex_we, &(game->tex_we), game->mlx_ptr))
		error("Erreur lors du chargement de la texture ouest.");
	if (!load_image(game->map.tex_s, &(game->tex_s), game->mlx_ptr))
		error("Erreur lors du chargement de la texture de l'objet.");
	if (!(game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.res[0],
		game->map.res[1], "cub3d")))
		error("Erreur lors de la creation de la fenetre.");
	if (!(game->img.img = mlx_new_image(game->mlx_ptr, game->map.res[0],
		game->map.res[1])))
		error("Erreur lors de la creation de l'image.");
	if (!(game->img.data = mlx_get_data_addr(game->img.img, &(game->img.bpp),
					&(game->img.size_line), &(game->img.endian))))
		error("Erreur avec les donnees de l'image.");
	game->img.w = game->map.res[0];
	game->img.h = game->map.res[1];
}

static void		place_player(t_game *game)
{
	t_list	*tmp;
	char	*s;
	int		i;
	int		j;

	tmp = game->map.map_d;
	j = 0;
	while (tmp)
	{
		s = (char*)tmp->content;
		i = -1;
		while (s[++i])
		{
			if (s[i] == '2')
				ft_lstadd_back(&(game->spritecoords), point_lstnew(i, j));
			if (s[i] == 'S' || s[i] == 'E' || s[i] == 'W' || s[i] == 'N')
			{
				game->p.pos = point(i * CUBE_SIZE + CUBE_SIZE / 2,
					j * CUBE_SIZE + CUBE_SIZE / 2);
				game->p.cam_angle = get_char_angle(s[i]);
			}
		}
		j++;
		tmp = tmp->next;
	}
}

int				main(int argc, char **argv)
{
	t_game	game;
	int		screenshot;

	if (argc < 2 || argc > 3)
		error("Nombre d'arguments invalide.");
	screenshot = (argc == 3 && !ft_strncmp(argv[2], "--save",
				(ft_strlen(argv[2]) > 6 ? ft_strlen(argv[2]) : 6)));
	if (argc == 3 && !screenshot)
		error("Second argument invalide.");
	init_game(&game);
	parse_map(argv[1], &(game.map));
	if (!(game.p.rays = malloc(sizeof(t_ray) * game.map.res[0])))
		error("Erreur d'allocation memoire.");
	setup_mlx(&game);
	place_player(&game);
	game.p.proj_dist = fabs((game.map.res[0] / 2.0) /
			tan(to_radians(FOV / 2.0)));
	mlx_hook(game.win_ptr, 2, 1L << 0, &key_pressed, &game);
	mlx_hook(game.win_ptr, 3, 1L << 1, &key_released, &game);
	mlx_hook(game.win_ptr, 17, 1L << 0, &close_event, &game);
	mlx_loop_hook(game.mlx_ptr, &actions, &game);
	render(&game, screenshot);
	mlx_loop(game.mlx_ptr);
	reset_map(&(game.map));
}
