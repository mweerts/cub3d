/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:06:09 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/02 22:15:30 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	read_map(t_info *info_map, int fd, char *line)
{
	int		i;
	char	*map_tmp;

	i = 0;
	if (!(map_tmp = (char *)malloc(sizeof(char))))
		error("L'allocation a echouee.");
	map_tmp[0] = 0;
	line = ft_strdup_map(line);
	map_tmp = ft_strjoin_point(map_tmp, line);
	free(line);
	while ((i = get_next_line(fd, &line)) != 0)
	{
		line = ft_strdup_map(line);
		map_tmp = ft_strjoin_point(map_tmp, line);
		free(line);
	}
	free(line);
	info_map->map = ft_split(map_tmp, '.');
	free(map_tmp);
	return (1);
}

static int	read_infos(char *s, t_info *info_map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if ((fd = open(s, O_RDWR)) == -1)
		error("L'ouverture de la map a echouee.");
	while (((i = get_next_line(fd, &line)) != 0) && !ft_is_wall(line[0]))
	{
		if (!get_map_infos(line, info_map))
			return (0);
		free(line);
	}
	read_map(info_map, fd, line);
	return (1);
}

int			read_management(char *s, t_info *info_map)
{
	t_len_map	len;

	if (check_extension(s) == 0)
		error("L'extension du fichier est incorrecte.");
	else
	{
		if ((read_infos(s, info_map)) == 0)
			return (0);
		if (!parse_management(info_map, &len))
			return (0);
	}
	return (1);
}
