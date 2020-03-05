/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:40:41 by mweerts           #+#    #+#             */
/*   Updated: 2020/03/05 02:04:11 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!(game->win_ptr = mlx_new_window(game->mlx_ptr, game->infos.screenWidth, game->infos.screenHeight, "cub3d")))
		error("Erreur lors de la création de la fenêtre.");
	game->player.posX = 50;
	game->player.posY = 50;
	game->keys.DOWN = 0;
	game->keys.LEFT = 0;
	game->keys.RIGHT = 0;
	game->keys.UP = 0;
	mlx_hook(game->win_ptr, 17, 1L << 17, exit_prog, 0);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, key_released, game);
	mlx_loop_hook(game->mlx_ptr, loop, game);
	mlx_loop(game->mlx_ptr);
}