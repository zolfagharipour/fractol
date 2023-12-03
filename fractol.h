#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "minilibx-linux/mlx.h"
#include "libft_math/libft_math.h"
#include "libft/libft.h"

# define W 1000
# define H 800

typedef struct	s_img {
	void		*mlx;
	void 		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	double		iter_mult;
	double		percission;
	t_complex	screen_begin;
}	t_img;


void	creat_img(char *name);
int		creat_trgb(int t, int r, int g, int b);
void	mandelbrot(t_img *img);



#endif