/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 02:00:42 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/10 19:51:05 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*mlx_ptr;
void	*win_ptr;

int exit_prog()
{
	ft_putstr_fd("Fermeture de cub3d\n", STDERR_FILENO);
	exit(EXIT_SUCCESS);
	return (0);
}

int key_hook(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit_prog();
	return (0);
}



int main()
{
	int width;
	int height;

	width = 200;
	height = 200;

	mlx_ptr = mlx_init();
	if (!(win_ptr = mlx_new_window(mlx_ptr, 600, 600, "miniRT")))
		return (error(1));
	mlx_hook(win_ptr, 17, 1L << 17, exit_prog, 0);
	mlx_key_hook(win_ptr, key_hook, 0);
	mlx_loop(mlx_ptr);
}
