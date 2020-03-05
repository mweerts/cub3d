NAME =	cub3d
SRCS = 	srcs/main.c \
		\
		srcs/utils/utils.c \
		srcs/utils/errors.c \
		srcs/utils/init.c \
		srcs/utils/hooks.c \
		\
		srcs/draw/draw.c \
		srcs/parser/parser.c

OBJS = $(SRCS:.c=.o)
LIBFT_PATH = libft/
LIBFT = libft.a
MLX_PATH = ./minilibx/
MLX = libmlx.a
FLAGS = #-Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory0

all: $(NAME)

$(NAME):	$(OBJS)
			@echo "\x1b[1m\x1b[32mMLX :\x1b[0m"
			make -C $(MLX_PATH)
			@echo "\x1b[1m\x1b[32mLIBFT :\x1b[0m"
			@mv $(MLX_PATH)$(MLX) .
			make -C $(LIBFT_PATH)
			@echo "\x1b[1m\x1b[32mCompiling cub3d\x1b[0m"
			@gcc -I includes/ $(OBJS) $(LIBFT_PATH)$(LIBFT) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)
			
clean:		
			@echo "\x1b[1m\x1b[31mCLEAN\x1b[0m"
			@make clean -C $(MLX_PATH)
			@make clean -C $(LIBFT_PATH)
			@rm -rf $(OBJS)

fclean:
			@echo "\x1b[1m\x1b[31mFORCE CLEAN\x1b[0m"
			@make clean -C $(MLX_PATH)
			@make clean -C $(LIBFT_PATH)
			@rm -rf $(OBJS)
			@rm -rf $(LIBFT_PATH)$(LIBFT)
			@rm -rf $(MLX)
			@rm -rf $(NAME)

re: fclean all

%.o: %.c
			gcc $(FLAGS) -I includes/ -c -o $@ $<
