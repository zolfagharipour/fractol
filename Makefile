
NAME = fractol

SRCS =  fractol.c image.c mandelbrot.c  fractol_utils.c julia.c\
		libft_math/ft_abs.c libft_math/ft_add_comp.c libft_math/ft_mult_comp.c \
		 libft_math/ft_size_com.c

OBJS = ${SRCS:.c=.o}


CC = cc
CFLAGS = -g
RM	=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	make --no-print-directory -C ./libft
	$(CC) $(OBJS) -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm ./libft/libft.a -o $@

%.o: %.c
	$(CC)  -c $< -o $@

clean: 

	${RM} ${OBJS} ${BONUS_OBJS}


fclean: clean
	${RM} ${NAME} ${CHECK}

re: fclean all

.PHONY: all bonus clean fclean re