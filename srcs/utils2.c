/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:35:55 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/01 19:37:12 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = 0;
	}
}

t_point		point(double x, double y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

t_list		*point_lstnew(double x, double y)
{
	t_point	*point;
	t_list	*elem;

	if (!(point = malloc(sizeof(t_point))))
		error("Erreur d'allocation memoire.");
	point->x = x;
	point->y = y;
	if (!(elem = ft_lstnew(point)))
		error("Erreur d'allocation memoire.");
	return (elem);
}

void		swap(t_point *p, t_point *p2)
{
	t_point tmp;

	tmp = *p;
	*p = *p2;
	*p2 = tmp;
}
