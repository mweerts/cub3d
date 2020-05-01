/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:36:42 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/01 19:36:34 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		load_image(char *file, t_image *img, void *mlx_ptr)
{
	if (!(img->img = mlx_xpm_file_to_image(mlx_ptr, file, &(img->w),
					&(img->h))))
		return (0);
	if (!(img->data = mlx_get_data_addr(img->img, &(img->bpp),
					&(img->size_line), &(img->endian))))
		return (0);
	return (1);
}

t_image	get_texture_face(t_game *game, int face)
{
	t_image textures[4];

	textures[0] = game->tex_no;
	textures[1] = game->tex_so;
	textures[2] = game->tex_we;
	textures[3] = game->tex_ea;
	if (face < 0 || face > 3)
		return (game->tex_no);
	return (textures[face]);
}

void	image_set_pixel(t_image *img, int x, int y, int color)
{
	if (!ft_inrange(x, 0, img->w) || !ft_inrange(y, 0, img->h))
		return ;
	*(int*)(img->data + ((x + (y * img->w)) * (img->bpp / 8))) = color;
}

int		image_get_color(t_image img, int x, int y)
{
	if (!ft_inrange(x, 0, img.w) || !ft_inrange(y, 0, img.h))
		return (0);
	return (*(int*)(img.data + ((x + (y * img.w)) * (img.bpp / 8))));
}
