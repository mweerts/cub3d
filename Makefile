# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mweerts <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 16:29:40 by mweerts           #+#    #+#              #
#    Updated: 2020/05/03 14:19:32 by mweerts          ###   ########.fr        #
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
		srcs/fill_map.c \
		srcs/hooks.c \
		srcs/player.c \
		srcs/exit_window.c \
		srcs/ray.c \
		srcs/texture.c \
		srcs/draw_wall_texture.c \
		srcs/save.c \
		srcs/sprite.c \
		srcs/init_storage.c
		
OBJS = $(SRCS:.c=.o)
LIBFT_PATH = libft/
LIBFT = libft.a
MLX_PATH = ./minilibx-linux/
MLX = libmlx.a
LIBFT_PATH = ./libft/
LIBFT = libft.a
FLAGS = #-Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
INCLUDES = -I includes/ -I libft/includes
FLAGS_MLX = -lbsd -lX11 -lXext -lm

all: $(NAME)

$(NAME):	$(OBJS)
			@echo "\033[0;32m\e[1mMLX\033[0m"
			@make -C $(MLX_PATH)
			@make -C $(LIBFT_PATH)
			@echo "\033[0;32m\e[1mCompiling cub3d\033[0m"
			@gcc $(INCLUDES) $(OBJS) $(MLX_PATH)$(MLX) $(LIBFT_PATH)$(LIBFT) $(FLAGS_MLX) -o $(NAME)
			
clean:		
			@echo "\033[0;32m\e[1mCLEAN\033[0m"
			@make clean -C $(MLX_PATH)
			@make clean -C $(LIBFT_PATH)
			@rm -rf $(OBJS)

fclean:
			@echo "\033[0;32m\e[1mFORCE CLEAN\033[0m"
			@make clean -C $(MLX_PATH)
			@make fclean -C $(LIBFT_PATH)
			@rm -rf $(OBJS)
			@rm -rf $(MLX)
			@rm -rf $(NAME)

re: fclean all

%.o: %.c
			@echo "\033[0;32m\e[1m[cub3d]\033[0m Compiling $@"
			@gcc $(FLAGS) $(INCLUDES) -c -o $@ $<
