/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:40:53 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/01 15:40:57 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_tile_at(t_point point, t_list *map_d)
{
	char *line;

	if (!ft_inrange(floor(point.y / CUBE_SIZE), 0, ft_lstsize(map_d)))
		return (-1);
	line = ft_lstat(map_d, floor(point.y / CUBE_SIZE))->content;
	if (!ft_inrange(floor(point.x / CUBE_SIZE), 0, ft_strlen(line)))
		return (-1);
	return (line[(int)(floor(point.x / CUBE_SIZE))]);
}

int		get_tile_at_grid(t_point point, t_list *map_d)
{
	char *line;

	if (!ft_inrange(floor(point.y), 0, ft_lstsize(map_d)))
		return (-1);
	line = ft_lstat(map_d, floor(point.y))->content;
	if (!ft_inrange(floor(point.x), 0, ft_strlen(line)))
		return (-1);
	return (line[(int)(floor(point.x))]);
}

void	set_tile_at(t_point point, char val, t_list *map_d)
{
	char *line;

	if (!ft_inrange(floor(point.y / CUBE_SIZE), 0, ft_lstsize(map_d)))
		return ;
	line = ft_lstat(map_d, floor(point.y / CUBE_SIZE))->content;
	if (!ft_inrange(floor(point.x / CUBE_SIZE), 0, ft_strlen(line)))
		return ;
	line[(int)(floor(point.x / CUBE_SIZE))] = val;
}

void	set_tile_at_grid(t_point point, char val, t_list *map_d)
{
	char *line;

	if (!ft_inrange(point.y, 0, ft_lstsize(map_d)))
		return ;
	line = ft_lstat(map_d, point.y)->content;
	if (!ft_inrange(point.x, 0, ft_strlen(line)))
		return ;
	line[(int)point.x] = val;
}