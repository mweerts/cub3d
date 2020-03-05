/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:38:18 by mweerts           #+#    #+#             */
/*   Updated: 2020/03/04 19:19:32 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb_to_int(t_color color)
{
	int	ret;

	ret = 0;
	ret += (int)color.blue;
	ret += (int)color.green * 256;
	ret += (int)color.red * 65536;

	return (ret); 
}

t_color	get_color(unsigned char red, unsigned char green, unsigned char blue)
{
	t_color color;

	color.red = red;
	color.green = green;
	color.blue = blue;
	return (color);
}
