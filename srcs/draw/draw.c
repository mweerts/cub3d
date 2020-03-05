/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:14:44 by mweerts           #+#    #+#             */
/*   Updated: 2020/03/05 01:26:23 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rectangle(int x, int y, int width, t_color color, t_game *game)
{
	int i;
	int j;

	i = 0;
	while(i < width)
	{
		j = 0;
		while(j < width)
		{
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + i, y + j, rgb_to_int(color));
			j++;
		}
		i++;
	}
}

void	draw_line(int x, int y, t_color color, t_game *game)
{
	
}
