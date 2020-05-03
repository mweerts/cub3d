/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:44:55 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/02 22:14:34 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			parse_map_vertically(t_info *info_map)
{
	int		i;
	int		n;

	i = 0;
	while (info_map->map[0][i])
	{
		if (info_map->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (info_map->map[i])
		i++;
	i--;
	info_map->len_map = i;
	n = 0;
	while (info_map->map[i][n])
	{
		if (info_map->map[i][n] != '1')
			return (0);
		n++;
	}
	return (1);
}

static void	get_line_len(t_info *info_map, t_len_map *len, int line)
{
	len->l1 = ft_strlen(info_map->map[line]);
	len->l2 = ft_strlen(info_map->map[line + 1]);
	len->check = len->l1 - len->l2;
}

static int	check_line1(t_info *info_map, t_len_map *len, int line)
{
	if (info_map->map[line][0] != '1')
		return (0);
	len->l1 = len->l1 - len->check;
	while (info_map->map[line][len->l1])
	{
		if (info_map->map[line][len->l1] != '1')
			return (0);
		len->l1++;
	}
	if (info_map->map[line + 1][0] != '1' ||
	info_map->map[line + 1][len->l2 - 1] != '1')
		return (0);
	return (1);
}

static int	check_line2(t_info *info_map, t_len_map *len, int line)
{
	if (info_map->map[line + 1][0] != '1')
		return (0);
	len->check *= -1;
	len->l2 = len->l2 - len->check;
	while (info_map->map[line + 1][len->l2])
	{
		if (info_map->map[line + 1][len->l2] != '1')
			return (0);
		len->l2++;
	}
	if (info_map->map[line][0] != '1' ||
	info_map->map[line][len->l1 - 1] != '1')
		return (0);
	return (1);
}

int			parse_map_horizontally(t_info *info_map, t_len_map *len)
{
	int		line;

	line = 1;
	while (info_map->map[line + 1] != NULL)
	{
		get_line_len(info_map, len, line);
		if (len->check == 0)
		{
			if (info_map->map[line][0] != '1' ||
			info_map->map[line][len->l1 - 1] != '1')
				return (0);
		}
		else if (len->check >= 1)
		{
			if (!check_line1(info_map, len, line))
				return (0);
		}
		else if (len->check < 0)
		{
			if (!check_line2(info_map, len, line))
				return (0);
		}
		line++;
	}
	return (1);
}
