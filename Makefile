
NAME = fractol

SRCS =  fractol.c image.c mandelbrot.c  fractol_utils.c julia.c newton.c events.c\
		libft_math/ft_abs.c libft_math/ft_add_comp.c libft_math/ft_mult_comp.c \
		libft_math/ft_size_com.c libft_math/ft_pow_comp.c libft_math/ft_dev_comp.c

OBJS = ${SRCS:.c=.o}


CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM	=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	make --no-print-directory -C ./libft
	$(CC) ${CFLAGS} $(OBJS) -Lminilibx-linux -lmlx -lX11 -lXext -lm ./libft/libft.a -o $@

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

clean:
	make --no-print-directory -C ./libft fclean
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME} ${CHECK}

re: fclean all

.PHONY: all bonus clean fclean re