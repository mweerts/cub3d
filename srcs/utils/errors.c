/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:27:40 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/04 18:02:27 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int error(int code)
{
    if (code == 1)
        write(2, "Erreur lors de la création de la fenetre\n", 42);
    exit(EXIT_FAILURE);
    return (1);
}