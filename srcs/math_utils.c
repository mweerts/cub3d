/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:41:14 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/01 15:41:17 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double			distance(t_point p, t_point p2)
{
	t_point dist;

	dist.x = p.x - p2.x;
	dist.y = p.y - p2.y;
	return (sqrt((dist.x * dist.x) + (dist.y * dist.y)));
}

double			to_radians(double angle)
{
	return (PI / 180 * angle);
}

double			constrain(double d, double min, double max)
{
	if (max < min)
		return (d);
	if (max == min)
		return (max);
	while (d < min)
		d += (max - min);
	while (d > max)
		d -= (max - min);
	return (d);
}

double			min(double d, double e)
{
	return (d < e ? d : e);
}

double			atan2(double y, double x)
{
	if (x > 0)
		return (atan(y / x));
	else if (x < 0 && y >= 0)
		return (atan(y / x) + PI);
	else if (x < 0 && y < 0)
		return (atan(y / x) - PI);
	else if (x == 0 && y > 0)
		return (PI / 2);
	else if (x == 0 && y < 0)
		return (-PI / 2);
	return (0);
}