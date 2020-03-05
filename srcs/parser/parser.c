/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:32:11 by mweerts           #+#    #+#             */
/*   Updated: 2020/03/04 17:27:23 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_line(t_info *infos, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'R')
	{
		i++;
		infos->screenWidth = ft_atoi(line + i++);
		while(line[i] != ' ')
			i++;
		infos->screenHeight = ft_atoi(line + i);
	}
	return (1);
}

int	parse(t_info *infos, char *path)
{
	int		fd;
	char	*line;

	if ((fd = open(path, O_RDONLY)) == -1)
		return(error("Erreur lors de l'ouverture du fichier."));
	while (get_next_line(fd, &line) == 1)
	{
		if(parse_line(infos, line) < 0)
			return(error("Erreur lors du parsing."));
	}
	return (1);
}