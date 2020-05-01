/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:41:39 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/01 19:28:27 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		parse_parameters(int fd, t_map *map)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strncmp(line, "R", 1) && ft_strncmp(line, "NO", 2) &&
		ft_strncmp(line, "SO", 2) && ft_strncmp(line, "EA", 2) &&
		ft_strncmp(line, "WE", 2) && ft_strncmp(line, "S ", 2) &&
		ft_strncmp(line, "F", 1) && ft_strncmp(line, "C", 1) && line[0])
			error("Parametre incorrect.");
		if (!ft_strncmp(line, "R", 1) && !parse_resolution(line, map))
			error("Resolution incorrecte.");
		else if ((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) ||
		!ft_strncmp(line, "EA", 2) || !ft_strncmp(line, "WE", 2) ||
		!ft_strncmp(line, "S", 1)) && !parse_texture(line, map))
			error("Texture incorrecte.");
		else if ((!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1)) &&
		!parse_color(line, map))
			error("Couleur incorrecte.");
		ft_strdel(&line);
		if (is_filled(*map))
			break ;
	}
	ft_strdel(&line);
	return (ret > -1);
}

static int		parse_description(int fd, t_map *map)
{
	int		ret;
	char	*line;
	t_list	*elem;
	int		end;

	while ((ret = get_next_line(fd, &line)))
	{
		if ((end = check_end(&line, map)) == 1)
			continue ;
		if (!(elem = ft_lstnew(line)))
			error("Erreur d'allocation memoire.");
		ft_lstadd_back(&map->map_d, elem);
	}
	ft_strdel(&line);
	if (ret == -1)
		error("Erreur lors de la lecture du fichier.");
	if (!check_map(map->map_d))
		error("Map incorrecte.");
	if (!format_description(map))
		error("Erreur d'allocation memoire.");
	return (ret > -1);
}

int				parse_map(char *filename, t_map *map)
{
	int fd;

	if (!ft_endswith(filename, ".cub"))
		error("Le fichier ne possede pas l'extension .cub.");
	if ((fd = open(filename, O_RDONLY)) <= 0)
		error("Erreur lors de l'ouverture du fichier.");
	if (!parse_parameters(fd, map))
		error("Erreur lors de la lecture du fichier.");
	if (!is_filled(*map))
		error("Parametres manquants.");
	if (!parse_description(fd, map))
		error("Erreur lors de la lecture du fichier.");
	return (1);
}
