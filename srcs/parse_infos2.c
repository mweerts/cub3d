/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:00:07 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/02 21:54:05 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_player_position(t_info *info_map, int i, int x)
{
	if (info_map->player_start == '0')
	{
		info_map->player_x = x;
		info_map->player_y = i;
		info_map->player_start = info_map->map[i][x];
		info_map->map[i][x] = '0';
	}
	else
		error("Vous avez specifie plusieurs positions de depart.");
	return (1);
}

void	get_nb_of_sprites(t_info *info_map)
{
	int		y;
	int		x;

	y = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x])
		{
			if (info_map->map[y][x] == '2')
				info_map->sprite_nb++;
			x++;
		}
		y++;
	}
}

void	get_sprite_position(t_info *info_map, t_storage *storage)
{
	int			y;
	int			x;
	int			n;

	y = 0;
	n = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x])
		{
			if (info_map->map[y][x] == '2')
			{
				storage->sprite[n].x = (double)x + 0.5;
				storage->sprite[n].y = (double)y + 0.5;
				n++;
			}
			x++;
		}
		y++;
	}
}
