/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:57:50 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/03 13:38:08 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_rgb(int nb[4], int n)
{
	if (nb[0] > 255 || nb[1] > 255 || nb[2] > 255)
		return (-2);
	else if (nb[0] < 0 || nb[1] < 0 || nb[2] < 0)
		return (-2);
	else
		nb[n] = 65536 * nb[0] + 256 * nb[1] + nb[2];
	return (nb[n]);
}

int		get_texture_west_east(char *s, t_info *info_map)
{
	int	i;

	i = 2;
	while (s[i] == ' ')
		i++;
	if (s[0] == 'W')
	{
		if (info_map->west_t[0] != '\0')
			error_texture(s);
		ft_strcpy(info_map->west_t, &s[i]);
	}
	else if (s[0] == 'E')
	{
		if (info_map->east_t[0] != '\0')
			error_texture(s);
		ft_strcpy(info_map->east_t, &s[i]);
	}
	else if (s[0] == 'S')
	{
		if (info_map->sprite_t[0] != '\0')
			error_texture(s);
		ft_strcpy(info_map->sprite_t, &s[i]);
	}
	return (1);
}

int		get_infos_resolution(char *s, t_info *info_map)
{
	if ((get_resolution(s, info_map)) == 0)
		error("Resolution invalide.");
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		check_space_rgb(char **tab, int i)
{
	int	n;
	int	valid;

	n = 0;
	valid = 0;
	while (tab[i][n])
	{
		if (tab[i][n] != ' ')
			valid = 1;
		n++;
	}
	if (valid == 0)
		return (0);
	return (1);
}
