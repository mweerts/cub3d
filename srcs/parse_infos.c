/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:56 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/03 16:58:10 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_extension(char *s)
{
	int		i;
	int		n;
	char	*cub;

	i = 0;
	cub = ".cub";
	while (s[i])
	{
		n = 0;
		while (s[i + n] == cub[n] && cub[n])
		{
			if (s[i + n + 1] == '\0' && cub[n + 1] == '\0')
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

static int	ckeck_textopening(t_info *info_map)
{
	if ((open(info_map->north_t, O_RDONLY)) == -1)
		error("L'ouverture de la texture Nord a echoue.");
	if ((open(info_map->south_t, O_RDONLY)) == -1)
		error("L'ouverture de la texture Sud a echoue.");
	if ((open(info_map->east_t, O_RDONLY)) == -1)
		error("L'ouverture de la texture Est a echoue.");
	if ((open(info_map->west_t, O_RDONLY)) == -1)
		error("L'ouverture de la texture Ouest a echoue.");
	return (1);
}

static int	parse_infos(t_info *info_map)
{
	if (info_map->rx <= 0 || info_map->ry <= 0)
		error("Resolution incorrecte.");
	info_map->rx = info_map->rx > MAXRES_X ? MAXRES_X : info_map->rx;
	info_map->ry = info_map->ry > MAXRES_Y ? MAXRES_Y : info_map->ry;
	if (info_map->colorf == -1)
		error("Couleur du sol manquante.");
	if (info_map->colorc == -1)
		error("Couleur du ciel manquante.");
	if (info_map->colorf < 0 || info_map->colorc < 0)
		error("La couleur specifiee est invalide.");
	if (!ckeck_textopening(info_map))
		error("L'ouverture de la texture a echoue.");
	return (1);
}

static int	check_map(t_info *info_map)
{
	int	i;
	int	x;

	i = 0;
	while (info_map->map[i])
	{
		x = 0;
		while (info_map->map[i][x])
		{
			if (info_map->map[i][x] != '0' && info_map->map[i][x] != '1' &&
			info_map->map[i][x] != '2' && info_map->map[i][x] != 'N' &&
			info_map->map[i][x] != 'S' && info_map->map[i][x] != 'E' &&
			info_map->map[i][x] != 'W')
				error("Caractere invalide.");
			if (info_map->map[i][x] == 'N' || info_map->map[i][x] == 'S' ||
			info_map->map[i][x] == 'E' || info_map->map[i][x] == 'W')
				if (!(get_player_position(info_map, i, x)))
					return (0);
			x++;
		}
		i++;
	}
	if (info_map->player_start == '0')
		error("Veuillez specifier une position de depart.");
	return (1);
}

int			parse_management(t_info *info_map, t_len_map *len)
{
	if (!parse_infos(info_map))
		return (0);
	if (!parse_map_vertically(info_map) ||
	!parse_map_horizontally(info_map, len))
		error("La map n'est pas entouree de murs.");
	if (!check_map(info_map))
		return (0);
	return (1);
}
