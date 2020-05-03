/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:02:44 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/02 22:46:58 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			expose(t_storage *s)
{
	int		i;

	i = 0;
	s->mlx->img = mlx_new_image(s->mlx->ptr, s->info->rx, s->info->ry);
	s->mlx->data_img = mlx_get_data_addr(s->mlx->img, &s->mlx->bpixel,
	&s->mlx->size_line, &s->mlx->endian);
	s->mlx->bpixel = s->mlx->bpixel / 8;
	while (i < s->info->rx * (s->info->ry / 2))
		*(int *)&s->mlx->data_img[i++ * s->mlx->bpixel] = s->info->colorc;
	while (i < s->info->rx * (s->info->ry))
		*(int *)&s->mlx->data_img[i++ * s->mlx->bpixel] = s->info->colorf;
	ft_raycaster(s, s->ray);
	sprite_management(s, s->sprite, s->info->sprite_nb);
	free(s->zbuffer);
	ft_player_pos_cam(s, s->player);
	mlx_put_image_to_window(s->mlx->ptr, s->mlx->win, s->mlx->img, 0, 0);
	if (s->save == 0)
		mlx_destroy_image(s->mlx->ptr, s->mlx->img);
	if (s->move->esc == 1)
		ft_exit_prog(s);
	return (0);
}

static int	management_program(t_info *map, t_mlx *mlx)
{
	t_move		move;
	t_player	player;
	t_ray		ray;
	t_storage	storage;
	t_texture	texture[6];

	get_sprite_position(map, &storage);
	init_movements(&move);
	init_player(&player);
	init_ray(&ray);
	fill_storage(&move, &ray, &storage);
	init_storage(map, mlx, &player, &storage);
	init_player_position(&storage, &player);
	if ((mlx->ptr = mlx_init()) == NULL)
		error("L'initialisation de la minilibx a echoue.");
	if (!(mlx->win = mlx_new_window(mlx->ptr, map->rx, map->ry, "Cub3d")))
		error("La creation de la fenetre a echoue.");
	if ((init_texture(&storage, texture, 64, 64) == 0))
		return (0);
	mlx_hook(mlx->win, 2, 1L << 0, ft_keypress, &move);
	mlx_hook(mlx->win, 3, 1L << 1, ft_keyrelease, &move);
	mlx_hook(mlx->win, 17, 1L << 0, ft_exit_prog, &storage);
	mlx_loop_hook(mlx->ptr, expose, &storage);
	mlx_loop(mlx->ptr);
	return (0);
}

static int	init_program(int save_nb, char **av, t_mlx mlx)
{
	t_info		info_map;

	init_map_infos(&info_map);
	if (!read_management(av[1], &info_map))
		return (0);
	ft_check_len_map(&info_map);
	get_nb_of_sprites(&info_map);
	if (save_nb == 1)
		save(&info_map, &mlx);
	else
		management_program(&info_map, &mlx);
	return (0);
}

int			main(int ac, char **av)
{
	int		save;
	t_mlx	mlx;

	save = 0;
	mlx.ptr = 0;
	if (ac < 2)
		error("Map manquante.");
	else if (ac > 3)
		error("Trop d'arguments.");
	else if (ac == 3)
	{
		if ((ft_strncmp(av[2], "--save", 7) != 0))
			error("Argument incorrect. Utilisez \"--save\".");
		else
			save = 1;
	}
	if (ac == 2 || (ac == 3 && save == 1))
		init_program(save, av, mlx);
	return (0);
}
