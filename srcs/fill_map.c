/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:51:59 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/03 14:24:46 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**fill_map(t_info *info_map, char **new_map, int len_max)
{
	int		y;
	int		x;

	y = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x] != '\0')
		{
			new_map[y][x] = info_map->map[y][x];
			x++;
		}
		new_map[y][x] = '\0';
		if (x <= len_max)
		{
			while (x <= len_max)
			{
				new_map[y][x] = '1';
				x++;
			}
			new_map[y][x] = '\0';
		}
		y++;
	}
	return (new_map);
}

static void	new_map(t_info *info_map, int len_y, int len_max)
{
	int		y;
	char	**new_map;

	if (!(new_map = (char **)malloc(sizeof(char *) * (len_y + 1))))
		return ;
	y = 0;
	while (y < len_y)
	{
		if (!(new_map[y] = (char *)malloc(sizeof(char) * (len_max + 1))))
			return ;
		y++;
	}
	new_map[y] = NULL;
	new_map = fill_map(info_map, new_map, len_max);
	y = 0;
	while (info_map->map[y])
		free(info_map->map[y++]);
	free(info_map->map);
	info_map->map = new_map;
}

void		map_len(t_info *info_map)
{
	int		y;
	int		x;
	int		len_max;

	y = 0;
	len_max = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x])
		{
			if (x > len_max)
				len_max = x;
			x++;
		}
		y++;
	}
	info_map->len_x = len_max;
	info_map->len_y = y;
	new_map(info_map, y, len_max);
}
