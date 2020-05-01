/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:37:12 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/01 19:41:16 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_key_index(int key)
{
	static int	keys[6] = {K_UP, K_DOWN, K_LEFT, K_RIGHT,
		K_CAMLEFT, K_CAMRIGHT};
	int			i;

	i = 0;
	while (i < 8)
	{
		if (keys[i] == key)
			return (i);
		i++;
	}
	return (-1);
}

int		key_released(int key, void *param)
{
	t_game	*game;
	int		ind;

	game = (t_game*)param;
	if ((ind = get_key_index(key)) != -1)
		game->keys[ind] = -1;
	return (0);
}

int		key_pressed(int key, void *param)
{
	t_game		*game;
	int			ind;

	game = (t_game*)param;
	if ((ind = get_key_index(key)) != -1)
		game->keys[ind] = key;
	if (key == K_ESC)
		quit(game);
	return (0);
}
