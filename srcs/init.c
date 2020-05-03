/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:40:18 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/03 15:58:07 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_infos(t_info *info_map)
{
	info_map->len_map = 0;
	info_map->rx = 0;
	info_map->ry = 0;
	info_map->north_t[0] = '\0';
	info_map->south_t[0] = '\0';
	info_map->west_t[0] = '\0';
	info_map->east_t[0] = '\0';
	info_map->sprite_t[0] = '\0';
	info_map->colorf = -1;
	info_map->colorc = -1;
	info_map->player_x = 0;
	info_map->player_y = 0;
	info_map->player_start = '0';
	info_map->sprite_nb = 0;
}

void	init_movements(t_move *move)
{
	move->esc = 0;
	move->foward = 0;
	move->retreat = 0;
	move->left = 0;
	move->right = 0;
	move->turn_left = 0;
	move->turn_right = 0;
}

void	init_player(t_player *player)
{
	player->pos_y = 0;
	player->pos_x = 0;
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
}

void	init_player_position(t_storage *storage, t_player *player)
{
	if (storage->info->player_start == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	if (storage->info->player_start == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		storage->ray->plane_x = -0.66;
	}
	if (storage->info->player_start == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		storage->ray->plane_x = 0;
		storage->ray->plane_y = -0.66;
	}
	if (storage->info->player_start == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		storage->ray->plane_x = 0;
		storage->ray->plane_y = 0.66;
	}
}

void	init_ray(t_ray *ray)
{
	ray->plane_x = 0.66;
	ray->plane_y = 0;
	ray->hit = 0;
}
