/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_storage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:51:34 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/02 22:26:26 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_storage(t_info *info_map, t_mlx *mlx, t_player *player,
t_storage *storage)
{
	storage->save = 0;
	storage->info = info_map;
	storage->mlx = mlx;
	storage->player = player;
	player->pos_x = storage->info->player_x + 0.5;
	player->pos_y = storage->info->player_y + 0.5;
}

void	fill_storage(t_move *move, t_ray *ray, t_storage *storage)
{
	storage->move = move;
	storage->ray = ray;
}
