# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mweerts <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 16:29:40 by mweerts           #+#    #+#              #
#    Updated: 2020/05/02 22:47:58 by mweerts          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	srcs/cub3d.c \
		srcs/read_map.c \
		srcs/parse_infos.c \
		srcs/parse_infos2.c \
		srcs/parse_map.c \
		srcs/get_infos.c \
		srcs/errors.c \
		srcs/init.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/ft_split.c \
		srcs/ft_strdup_map.c \
		srcs/ft_strcpy.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/ft_fill_map.c \
		srcs/ft_keyboard_action.c \
		srcs/ft_movement_player.c \
		srcs/ft_exit_prog.c \
		srcs/ft_raycaster.c \
		srcs/texture.c \
		srcs/ft_memcpy.c \
		srcs/ft_strncmp.c \
		srcs/draw_wall_texture.c \
		srcs/save.c \
		srcs/sprite.c \
		srcs/init_storage.c
		
OBJS = $(SRCS:.c=.o)
LIBFT_PATH = libft/
LIBFT = libft.a
MLX_PATH = ./minilibx-linux/
MLX = libmlx.a
FLAGS = #-Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
INCLUDES = -I includes/ 


all: $(NAME)

$(NAME):	$(OBJS)
			@echo "\033[0;32m\e[1mMLX\033[0m"
			@make -C $(MLX_PATH)
			@echo "\033[0;32m\e[1mCompiling cub3d\033[0m"
			@gcc $(INCLUDES) $(OBJS) $(MLX_PATH)$(MLX) -lbsd -lX11 -lXext -lm -o $(NAME)
			
clean:		
			@echo "\033[0;32m\e[1mCLEAN\033[0m"
			@make clean -C $(MLX_PATH)
			@rm -rf $(OBJS)

fclean:
			@echo "\033[0;32m\e[1mFORCE CLEAN\033[0m"
			@make clean -C $(MLX_PATH)
			@rm -rf $(OBJS)
			@rm -rf $(MLX)
			@rm -rf $(NAME)

re: fclean all

%.o: %.c
			@echo "\033[0;32m\e[1m[cub3d]\033[0m Compiling $@"
			@gcc $(FLAGS) $(INCLUDES) -c -o $@ $<
