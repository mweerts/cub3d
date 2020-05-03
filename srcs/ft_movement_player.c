/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:47:58 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/02 19:04:16 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player_pos_x(t_storage *s, t_player *p)
{
	if (s->move->left == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x - s->ray->plane_x
		* MOVE_SPEED)] != '1')
			p->pos_x = p->pos_x - s->ray->plane_x * MOVE_SPEED;
		if (s->info->map[(int)(p->pos_y - s->ray->plane_y * MOVE_SPEED)]
		[(int)(p->pos_x)] != '1')
			p->pos_y = p->pos_y - s->ray->plane_y * MOVE_SPEED;
	}
	if (s->move->right == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x + s->ray->plane_x
		* MOVE_SPEED)] != '1')
			p->pos_x = p->pos_x + s->ray->plane_x * MOVE_SPEED;
		if (s->info->map[(int)(p->pos_y + s->ray->plane_y * MOVE_SPEED)]
		[(int)(p->pos_x)] != '1')
			p->pos_y = p->pos_y + s->ray->plane_y * MOVE_SPEED;
	}
}

void	ft_player_pos_dir(t_storage *s, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	if (s->move->turn_left == 1)
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-CAM_SPEED) - p->dir_y * sin(-CAM_SPEED);
		p->dir_y = old_dir_x * sin(-CAM_SPEED) + p->dir_y * cos(-CAM_SPEED);
		old_plane_x = s->ray->plane_y;
		s->ray->plane_y = s->ray->plane_y * cos(CAM_SPEED) - s->ray->plane_x
		* sin(CAM_SPEED);
		s->ray->plane_x = old_plane_x * sin(CAM_SPEED) + s->ray->plane_x
		* cos(CAM_SPEED);
	}
	if (s->move->turn_right == 1)
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(CAM_SPEED) - p->dir_y * sin(CAM_SPEED);
		p->dir_y = old_dir_x * sin(CAM_SPEED) + p->dir_y * cos(CAM_SPEED);
		old_plane_x = s->ray->plane_y;
		s->ray->plane_y = s->ray->plane_y * cos(-CAM_SPEED) - s->ray->plane_x
		* sin(-CAM_SPEED);
		s->ray->plane_x = old_plane_x * sin(-CAM_SPEED) + s->ray->plane_x
		* cos(-CAM_SPEED);
	}
}

void	ft_player_pos_cam(t_storage *s, t_player *p)
{
	if (s->move->foward == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x
		* MOVE_SPEED)] != '1')
			p->pos_x += p->dir_x * MOVE_SPEED;
		if (s->info->map[(int)(p->pos_y + p->dir_y * MOVE_SPEED)]
		[(int)(p->pos_x)] != '1')
			p->pos_y += p->dir_y * MOVE_SPEED;
	}
	if (s->move->retreat == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x - p->dir_x
		* MOVE_SPEED)] != '1')
			p->pos_x -= p->dir_x * MOVE_SPEED;
		if (s->info->map[(int)(p->pos_y - p->dir_y * MOVE_SPEED)]
		[(int)(p->pos_x)] != '1')
			p->pos_y -= p->dir_y * MOVE_SPEED;
	}
	ft_player_pos_x(s, p);
	ft_player_pos_dir(s, p);
}
