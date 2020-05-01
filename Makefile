NAME =	cub3d
SRCS = 	srcs/main.c \
		srcs/actions.c \
		srcs/camera.c \
		srcs/check_map.c \
		srcs/events.c \
		srcs/format_description.c \
		srcs/ft_skipcharset.c \
		srcs/image.c \
		srcs/map.c \
		srcs/math_utils.c \
		srcs/parse_utils.c \
		srcs/parser.c \
		srcs/ray.c \
		srcs/render.c \
		srcs/rendersprite.c \
		srcs/renderwall.c \
		srcs/screenshot.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/utils3.c 


OBJS = $(SRCS:.c=.o)
LIBFT_PATH = libft/
LIBFT = libft.a
MLX_PATH = ./minilibx-linux/
MLX = libmlx.a
FLAGS = #-Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
INCLUDES = -I includes/ -I libft/includes

all: $(NAME)

$(NAME):	$(OBJS)
			@echo "\033[0;32m\e[1mMLX\033[0m"
			@make -C $(MLX_PATH)
			@echo "\033[0;32m\e[1mLIBFT\033[0m"
			@make -C $(LIBFT_PATH)
			@echo "\033[0;32m\e[1mCompiling cub3d\033[0m"
			@gcc $(INCLUDES) $(OBJS) $(LIBFT_PATH)$(LIBFT) $(MLX_PATH)$(MLX) -lbsd -lX11 -lXext -lm -o $(NAME)
			
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
