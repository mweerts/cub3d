/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 02:00:51 by mweerts           #+#    #+#             */
/*   Updated: 2020/03/05 01:57:52 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_color;

typedef struct	s_info
{
	int		screenWidth;
	int		screenHeight;
	char	*textNorth;
	char	*textSouth;
	char	*textEast;
	char	*textWest;
	char	*textSprite;
	t_color	colorSol;
	t_color	colorPlafond;
}				t_info;

typedef	struct	s_player
{
	int		posX;
	int		posY;
}				t_player;

typedef	struct	s_keys
{
	char	UP;
	char	DOWN;
	char	LEFT;
	char	RIGHT;
}				t_keys;


typedef struct	s_game
{
	t_info		infos;
	t_player	player;
	t_keys		keys;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_game;

int		rgb_to_int(t_color color);
void	ft_putnbr_base(int nbr, char *base);
int     error(char *description);
int		parse(t_info *infos, char *path);
void	init_game(t_game *game);
int		key_pressed(int keycode, void *param);
int		key_released(int keycode, void *param);
int		exit_prog();
t_color	get_color(unsigned char red, unsigned char green, unsigned char blue);
void	draw_rectangle(int x, int y, int width, t_color color, t_game *game);
void	draw_line(int x, int y, t_color color, t_game *game);
int		loop(void *param);

#endif
