/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 02:00:51 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/04 18:02:14 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

int		rgb_to_int(unsigned char red, unsigned char green, unsigned char blue);
void	ft_putnbr_base(int nbr, char *base);
int     error(int code);
#endif