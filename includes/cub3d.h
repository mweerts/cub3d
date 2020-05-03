/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:02:53 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/03 14:29:02 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307

# define MAXRES_X 1920
# define MAXRES_Y 1080

# define MOVE_SPEED 0.05
# define CAM_SPEED 0.05

typedef struct		s_sprite
{
	double	x;
	double	y;
}					t_sprite;

typedef struct		s_sprite_info
{
	int		i;
	int		d;
	int		nb;
	double	x;
	double	y;
	double	inv_det;
	double	transformx;
	double	transformy;
	int		screen_x;
	int		height;
	int		drawstart_y;
	int		drawend_y;
	int		width;
	int		drawstart_x;
	int		drawend_x;
	int		texwidth;
	int		texheight;
	int		texx;
	int		texy;
	int		texture;
}					t_sprite_info;

typedef	struct		s_info
{
	char	**map;
	int		len_map;
	int		len_x;
	int		len_y;
	int		rx;
	int		ry;
	char	north_t[256];
	char	south_t[256];
	char	west_t[256];
	char	east_t[256];
	char	sprite_t[256];
	int		colorf;
	int		colorc;
	int		player_y;
	int		player_x;
	char	player_start;
	int		sprite_nb;
}					t_info;

typedef struct		s_player
{
	double	pos_y;
	double	pos_x;
	float	x;
	float	y;
	double	dir_x;
	double	dir_y;
}					t_player;

typedef struct		s_mlx
{
	void	*ptr;
	void	*win;
	char	*img;
	char	*data_img;
	int		bpixel;
	int		size_line;
	int		endian;
}					t_mlx;

typedef struct		s_move
{
	int				esc;
	int				foward;
	int				retreat;
	int				left;
	int				right;
	int				turn_left;
	int				turn_right;
}					t_move;

typedef struct		s_ray
{
	double			plane_x;
	double			plane_y;
	double			cam_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
}					t_ray;

typedef struct		s_len_map
{
	int		l1;
	int		l2;
	int		check;
}					t_len_map;

typedef struct		s_text_info
{
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	wallx;
	int		x;
	int		y;
	int		width;
	int		height;
}					t_text_info;

typedef struct		s_texture
{
	void	*ptr;
	char	*img;
	int		bpixel;
	int		size_line;
	int		endian;
}					t_texture;

typedef struct		s_save
{
	int			fd;
	int			size;
	int			unused;
	int			offset_begin;
	int			header_bytes;
	short int	plane;
	short int	bpixel;
}					t_save;

typedef	struct		s_storage
{
	t_info		*info;
	t_mlx		*mlx;
	t_player	*player;
	t_move		*move;
	t_ray		*ray;
	t_texture	*texture;
	t_sprite	sprite[50];
	double		*zbuffer;
	int			save;
}					t_storage;

int					expose(t_storage *storage);
int					read_management(char *s, t_info *info_map);
int					check_extension (char *s);
int					parse_management(t_info *info_map, t_len_map *len);
int					parse_map_vertically(t_info *info_map);
int					parse_map_horizontally(t_info *info_map, t_len_map *len);
int					get_resolution(char *s, t_info *info_map);
int					get_texture_west_east(char *s, t_info *info_map);
int					get_map_infos(char *s, t_info *info_map);
int					ft_management_error(int error, char *s);
void				init_map_infos(t_info *info_map);
void				init_movements(t_move *move);
void				init_player(t_player *player);
void				init_ray(t_ray *ray);
void				init_player_position(t_storage *storage, t_player *player);
void				init_storage(t_info *info_map, t_mlx *mlx,
t_player			*player, t_storage *storage);
void				fill_storage(t_move *move, t_ray *ray,
									t_storage *storage);
void				map_len(t_info *info_map);
void				error_texture(char *texture);
void				error(char *msg);
int					exit_window(t_storage *storage);
int					key_released(int keycode, t_move *move);
int					key_pressed(int keycode, t_move *move);
void				camera_position(t_storage *storage, t_player *player);
void				cast_rays(t_storage *storage, t_ray *ray);
int					init_texture(t_storage *storage, t_texture *texture,
									int w, int h);
void				texture_management(t_storage *storage, t_ray *ray,
											int x);
void				draw_wall_north_south(t_storage *s, t_texture *texture,
											t_text_info	*text_i, int x);
void				draw_wall_east_west(t_storage *s, t_texture *texture,
											t_text_info *text_i, int x);
void				save(t_info *info_map, t_mlx *mlx);
int					get_player_position(t_info *info_map, int i, int x);
void				get_nb_of_sprites(t_info *info_map);
void				get_sprite_position(t_info *info_map, t_storage *storage);
void				sprite_management(t_storage *s, t_sprite *sprite,
										int sprite_nb);
int					ft_is_wall(char c);
char				*ft_strjoin_point(char *s1, char *s2);
int					check_rgb(int nb[4], int n);
int					get_infos_resolution(char *s, t_info *info_map);
void				free_tab(char **tab);
int					check_space_rgb(char **tab, int i);
char				*ft_strdup_map(char *s);
int					get_next_line(int fd, char **line);

#endif
