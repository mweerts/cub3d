/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 01:38:04 by mweerts           #+#    #+#             */
/*   Updated: 2020/03/05 01:56:32 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_pressed(int keycode, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keycode == 53)
		exit_prog();
	if (keycode == 123)
		game->keys.LEFT = 1;
	if (keycode == 124)
		game->keys.RIGHT = 1;
	if (keycode == 125)
		game->keys.UP = 1;
	if (keycode == 126)
		game->keys.DOWN = 1;

	return (1);
}	

int		key_released(int keycode, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keycode == 123)
		game->keys.LEFT = 0;
	if (keycode == 124)
		game->keys.RIGHT = 0;
	if (keycode == 125)
		game->keys.UP = 0;
	if (keycode == 126)
		game->keys.DOWN = 0;

	return (1);
}	

int		loop(void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (game->keys.UP)
		game->player.posY += 1;
	if (game->keys.DOWN)
		game->player.posY -= 1;
	if (game->keys.LEFT)
		game->player.posX -= 1;
	if (game->keys.RIGHT)
		game->player.posX += 1;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_rectangle(game->player.posX, game->player.posY, 500, get_color(255, 255, 255), game);
	return (1);
}