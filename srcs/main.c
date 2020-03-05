/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 02:00:42 by mweerts           #+#    #+#             */
/*   Updated: 2020/03/05 01:42:55 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int exit_prog()
{
	ft_putstr_fd("Fermeture de cub3d\n", STDERR_FILENO);
	exit(EXIT_SUCCESS);
	return (0);
}

int key_hook(int keycode, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keycode == 53)
		exit_prog();
	if (keycode == 123)
		game->player.posX -= 1;
	if (keycode == 124)
		game->player.posX += 1;
	if (keycode == 125)
		game->player.posY += 1;
	if (keycode == 126)
		game->player.posY -= 1;

	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_rectangle(game->player.posX, game->player.posY, 500, get_color(255, 255, 255), game);

	return (0);
}

/*void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!(game->win_ptr = mlx_new_window(game->mlx_ptr, game->infos.screenWidth, game->infos.screenHeight, "cub3d")))
		error("Erreur lors de la création de la fenêtre.");
	mlx_hook(game->win_ptr, 17, 1L << 17, exit_prog, 0);
	mlx_key_hook(game->win_ptr, key_hook, 0);
	mlx_loop(game->mlx_ptr);
}*/

int main(int argc, char **argv)
{
	t_game game;

	//if (argc < 2)
	//	return(error("Argument manquant."));

	parse(&game.infos, "test.cub");
	init_game(&game);
	draw_rectangle(game.player.posX, game.player.posY, 500, get_color(255, 255, 255), &game);
	mlx_loop(game.mlx_ptr);
}
