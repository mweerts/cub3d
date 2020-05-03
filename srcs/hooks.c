/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:05:28 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/03 14:05:31 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_released(int keycode, t_move *move)
{
	if (keycode == KEY_ESC)
		move->esc = 0;
	else if (keycode == KEY_W)
		move->foward = 0;
	else if (keycode == KEY_S)
		move->retreat = 0;
	else if (keycode == KEY_A)
		move->left = 0;
	else if (keycode == KEY_D)
		move->right = 0;
	else if (keycode == KEY_LEFT)
		move->turn_left = 0;
	else if (keycode == KEY_RIGHT)
		move->turn_right = 0;
	return (0);
}

int	key_pressed(int keycode, t_move *move)
{
	if (keycode == KEY_ESC)
		move->esc = 1;
	else if (keycode == KEY_W)
		move->foward = 1;
	else if (keycode == KEY_S)
		move->retreat = 1;
	else if (keycode == KEY_A)
		move->left = 1;
	else if (keycode == KEY_D)
		move->right = 1;
	else if (keycode == KEY_LEFT)
		move->turn_left = 1;
	else if (keycode == KEY_RIGHT)
		move->turn_right = 1;
	return (0);
}
