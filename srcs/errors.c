/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:04:43 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/02 22:16:47 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *msg)
{
	ft_putstr("Error\n");
	ft_putstr(msg);
	ft_putstr("\n");
	exit(0);
}

void	error_texture(char *texture)
{
	ft_putstr("Error\n");
	ft_putstr("La texture ");
	ft_putstr(texture);
	ft_putstr(" est deja initialisee.");
	ft_putstr("\n");
	exit(0);
}
