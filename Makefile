

SRCS            = src/main.c src/init/init_map.c src/checks/check_map.c \
					src/checks/check_path.c src/init/init_player.c \
					src/game.c src/movement.c src/free_func.c \
					src/checks/check_movement.c src/create_map.c \
					src/checks/check_map2.c

SRCS_BONUS            = bonus/src/main.c bonus/src/init/init_map.c bonus/src/checks/check_map.c \
					bonus/src/checks/check_path.c bonus/src/init/init_player.c \
					bonus/src/game.c bonus/src/movement/movement.c bonus/src/free_func.c \
					bonus/src/checks/check_movement.c bonus/src/create_map.c \
					bonus/src/checks/check_map2.c bonus/src/sprites/sprite_player.c \
					bonus/src/display_mes.c bonus/src/movement/sense_move.c

OBJS            = $(SRCS:.c=.o)

OBJS_BONUS            = $(SRCS_BONUS:.c=.o)

CC              = cc

RM              = rm -f

CFLAGS          =  -g -Wall -Wextra -Werror

LIBFT			= ./Libft/libft.a

LIBMLX			= ./mlx_linux/libmlx_Linux.a

NAME            = so_long

NAME_BONUS      = so_long_bonus

all:            $(NAME)

bonus:            $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):	
	$(MAKE) -C ./Libft

$(LIBMLX):	
	$(MAKE) -C ./mlx_linux	

$(NAME):        $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(OBJS) $(LIBFT) $(LIBMLX)

$(NAME_BONUS):        $(OBJS_BONUS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT) $(LIBMLX)	

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:         clean
	$(RM) $(NAME) $(NAME_BONUS)

re:             fclean $(NAME) $(NAME_BONUS)

.PHONY:         all clean fclean re 
