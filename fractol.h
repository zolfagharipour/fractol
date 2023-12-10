#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <math.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
// # include <mlx.h>
# include "minilibx-linux/mlx.h"
# include "libft_math/libft_math.h"
# include "libft/libft.h"

# define W 2600
# define H 1440

typedef struct	s_img {
	void		*mlx;
	void 		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			ac;
	int			color;
	int			wing;
	char		**av;
	double		iter_mult;
	double		percission;
	t_complex	julia;
	t_complex	lambda;
	t_complex	screen_begin;
}	t_img;


void	creat_img(int ac, char **av);
int		event_handler(t_img *img);
void	run_set(t_img *img);
void	fractal_init(t_img *img, int ac, char **av);
int		creat_trgb(int t, int r, int g, int b);
double	ft_atof(const char *nptr);
void	mandelbrot(t_img *img);
void	julia(t_img *img);
void	newton(t_img *img);




#endif