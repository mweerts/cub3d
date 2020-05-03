/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:34:18 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/03 13:41:28 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_texture_data(t_texture *texture)
{
	texture[0].img = mlx_get_data_addr(texture[0].ptr, &texture[0].bpixel,
	&texture[0].size_line, &texture[0].endian);
	if (texture[0].img == NULL)
		error("Initialisation de la texture nord impossible.");
	texture[1].img = mlx_get_data_addr(texture[1].ptr, &texture[1].bpixel,
	&texture[1].size_line, &texture[1].endian);
	if (texture[1].img == NULL)
		error("Initialisation de la texture sud impossible.");
	texture[2].img = mlx_get_data_addr(texture[2].ptr, &texture[2].bpixel,
	&texture[2].size_line, &texture[2].endian);
	if (texture[2].img == NULL)
		error("Initialisation de la texture ouest impossible.");
	texture[3].img = mlx_get_data_addr(texture[3].ptr, &texture[3].bpixel,
	&texture[3].size_line, &texture[3].endian);
	if (texture[3].img == NULL)
		error("Initialisation de la texture est impossible.");
	texture[4].img = mlx_get_data_addr(texture[4].ptr, &texture[4].bpixel,
	&texture[4].size_line, &texture[4].endian);
	if (texture[4].img == NULL)
		error("Initialisation de la texture du sprite impossible.");
	return (1);
}

int			init_texture(t_storage *s, t_texture *texture, int w,
int h)
{
	if ((texture[0].ptr = mlx_xpm_file_to_image(s->mlx->ptr,
	s->info->north_t, &w, &h)) == NULL)
		error("Initialisation de la texture nord impossible.");
	if ((texture[1].ptr = mlx_xpm_file_to_image(s->mlx->ptr,
	s->info->south_t, &w, &h)) == NULL)
		error("Initialisation de la texture sud impossible.");
	if ((texture[2].ptr = mlx_xpm_file_to_image(s->mlx->ptr,
	s->info->west_t, &w, &h)) == NULL)
		error("Initialisation de la texture ouest impossible.");
	if ((texture[3].ptr = mlx_xpm_file_to_image(s->mlx->ptr,
	s->info->east_t, &w, &h)) == NULL)
		error("Initialisation de la texture est impossible.");
	if ((texture[4].ptr = mlx_xpm_file_to_image(s->mlx->ptr,
	s->info->sprite_t, &w, &h)) == NULL)
		error("Initialisation de la texture du sprite impossible.");
	texture[5].ptr = NULL;
	init_texture_data(texture);
	s->texture = texture;
	return (1);
}

static void	init_value(t_storage *s, t_text_info *text_i, t_ray *ray)
{
	text_i->width = 64;
	text_i->height = 64;
	text_i->lineheight = (int)(s->info->ry / ray->perpwalldist);
	text_i->drawstart = -text_i->lineheight / 2 + s->info->ry / 2;
	if (text_i->drawstart < 0)
		text_i->drawstart = 0;
	text_i->drawend = text_i->lineheight / 2 + s->info->ry / 2;
	if (text_i->drawend >= s->info->ry)
		text_i->drawend = s->info->ry - 1;
	if (ray->side == 0)
		text_i->wallx = s->player->pos_y + ray->perpwalldist
	* ray->raydir_y;
	else
		text_i->wallx = s->player->pos_x + ray->perpwalldist
	* ray->raydir_x;
	text_i->wallx -= floor(text_i->wallx);
	text_i->x = (int)(text_i->wallx * (double)text_i->width);
	if (ray->side == 0 && ray->raydir_x > 0)
		text_i->x = text_i->width - text_i->x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		text_i->x = text_i->width - text_i->x - 1;
}

void		texture_management(t_storage *s, t_ray *ray, int x)
{
	t_text_info		text_i;

	init_value(s, &text_i, ray);
	if (ray->side == 1)
		draw_wall_north_south(s, s->texture, &text_i, x);
	else
		draw_wall_east_west(s, s->texture, &text_i, x);
}
