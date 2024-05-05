NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -Iheaders/

MLX_PATH = lib/minilibx
FRMS = -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
MLX = libmlx.a

LIBFT_PATH = lib/libft
LIBFT	= libft.a
LIBFT_ARC = $(LIBFT_PATH)/$(LIBFT)

FT_PRINTF_PATH = lib/ft_printf
FT_PRINTF = libftprintf.a
FT_PRINTF_ARC = $(FT_PRINTF_PATH)/$(FT_PRINTF)

GNL_PATH = lib/get_next_line
GNL	= libftgnl.a
GNL_ARC = $(GNL_PATH)/$(GNL)

SRCS = 	so_long.c					\
		create_map.c				\
		check_map_1.c				\
		check_map_2.c				\
		graphic_management.c		\
		handler_functions.c			\

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C $(MLX_PATH) -j16 2> /dev/null
	@make -s -C $(LIBFT_PATH)
	@make -s -C $(GNL_PATH)
	@make -s -C $(FT_PRINTF_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) $(FT_PRINTF_ARC) $(GNL_ARC) $(FRMS) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean
	@make -C $(GNL_PATH) clean
	@make -C $(MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(FT_PRINTF_PATH) fclean
	@make -C $(GNL_PATH) fclean

re: fclean all
