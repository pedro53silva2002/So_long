

SRCS            = src/main.c src/init_map.c src/check_map.c \
					src/check_path.c src/init_player.c \
					src/game.c src/movement.c src/free_func.c \
					src/check_movement.c src/create_map.c
OBJS            = $(SRCS:.c=.o)


CC              = cc

RM              = rm -f

CFLAGS          =  -g -Wall -Wextra -Werror

LIBFT			= ./Libft/libft.a

LIBMLX			= ./mlx_linux/libmlx_Linux.a

NAME            = so_long

all:            $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):	
	$(MAKE) -C ./Libft

$(LIBMLX):	
	$(MAKE) -C ./mlx_linux	

$(NAME):        $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(OBJS) $(LIBFT) $(LIBMLX)

clean:
	$(RM) $(OBJS)

fclean:         clean
	$(RM) $(NAME)

re:             fclean $(NAME)

.PHONY:         all clean fclean re 
