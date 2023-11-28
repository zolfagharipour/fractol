
NAME = mlx

SRCS =  mlx.c ../libft_math/ft_abs.c ../libft_math/ft_add_comp.c ../libft_math/ft_mult_comp.c ../libft_math/ft_pow.c \
		../libft_math/ft_root.c ../libft_math/ft_size_com.c

OBJS = ${SRCS:.c=.o}


CC = cc
CFLAGS = -g
RM	=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}

	$(CC) $(OBJS) -I/usr/include -L/usr/lib -Imlx -lmlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC)  -c $< -o $@

clean: 

	${RM} ${OBJS} ${BONUS_OBJS}


fclean: clean
	${RM} ${NAME} ${CHECK}

re: fclean all

.PHONY: all bonus clean fclean re