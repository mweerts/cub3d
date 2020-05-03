/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:49:26 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/02 22:22:12 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_resolution(char *s, t_info *info_map)
{
	int	i;

	i = 2;
	if (info_map->rx > 0 || info_map->rx > 0)
		return (0);
	info_map->rx = ft_atoi(&s[i]);
	while (s[i] != ' ')
		i++;
	info_map->ry = ft_atoi(&s[i]);
	return (1);
}

static int	get_texture_path(char *s, t_info *info_map)
{
	int	i;

	i = 2;
	while (s[i] == ' ')
		i++;
	if (s[0] == 'N')
	{
		if (info_map->north_t[0] != '\0')
			error("La texture est deja initialisee.");
		ft_strcpy(info_map->north_t, &s[i]);
	}
	else if (s[0] == 'S' && s[1] == 'O')
	{
		if (info_map->south_t[0] != '\0')
			error("La texture est deja initialisee.");
		ft_strcpy(info_map->south_t, &s[i]);
	}
	return (1);
}

static int	convert_rgb(char *s)
{
	int		i;
	int		nb[4];
	char	**tab;

	i = 0;
	tab = ft_split(&s[1], ',');
	while (tab[i])
		i++;
	if (i > 3)
		error("Couleur incorrecte.");
	i = 0;
	while (i < 3)
	{
		if ((tab[i] == NULL) || !check_space_rgb(tab, i))
			error("Couleur incorrecte.");
		else
		{
			nb[i] = ft_atoi(tab[i]);
			i++;
		}
	}
	free_tab(tab);
	nb[i] = check_rgb(nb, i);
	return (nb[i]);
}

static int	get_color(char *s, t_info *info_map)
{
	if (s[0] == 'F' && info_map->colorf == 0)
		info_map->colorf = convert_rgb(s);
	else if (s[0] == 'C' && info_map->colorc == 0)
		info_map->colorc = convert_rgb(s);
	else
		error("Couleur deja initialisee.");
	if (info_map->colorf == -1 || info_map->colorc == -1)
		return (0);
	return (1);
}

int			get_map_infos(char *s, t_info *info_map)
{
	if (s[0] == 'R')
		return (get_infos_resolution(s, info_map));
	else if ((s[0] == 'N' && s[1] == 'O') || (s[0] == 'S' && s[1] == 'O'))
	{
		if ((get_texture_path(s, info_map)) == 0)
			return (0);
	}
	else if ((s[0] == 'W' && s[1] == 'E')
	|| (s[0] == 'E' && s[1] == 'A') || (s[0] == 'S' && s[1] == ' '))
	{
		if ((get_texture_west_east(s, info_map)) == 0)
			return (0);
	}
	else if (s[0] == 'F' || s[0] == 'C')
	{
		if ((get_color(s, info_map)) == 0)
			return (0);
	}
	else if (s[0] == '\n' || s[0] == '\0')
		return (1);
	else
		error_texture(s);
	return (1);
}
