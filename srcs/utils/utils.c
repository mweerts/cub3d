/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:38:18 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/04 18:02:34 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb_to_int(unsigned char red, unsigned char green, unsigned char blue)
{
	int	ret;

	ret = 0;
	ret += (int)blue;
	ret += (int)green * 256;
	ret += (int)red * 65536;

	return (ret); 
}