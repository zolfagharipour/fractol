#include "fractol.h"

static void	pixel_put(t_img *img, t_vector i, int color)
{
	char *dst;

	// img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	dst = img->addr + (i.y * img->line_length + i.x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

static void print_screen(t_img *img, int screen[W][H])
{
	t_vector	i;
	int			color;
	int			offset;

	i.y = 0;
	i.x = 0;
	color = 0;
	offset = 0;
	while (i.y < H)
	{
		i.x = 0;
		while (i.x < W)
		{
			offset = (i.y * img->line_length + i.x * (img->bpp / 8));
			color = screen[i.x][i.y];
			color = creat_trgb(0, color * 8 + 10, color * 8 / 2, color * 7 + 30);
			*(unsigned int *)(img->addr + offset) = color;
			i.x++;
		}
		i.y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}


static int	converge(int iter_mult, t_complex z, t_complex c)
{
	int	i;

	i = 0;
	while (i < 50 * iter_mult)
	{
		z = ft_mult_comp(z, z);
		z = ft_add_comp(z, c);
		if (ft_size_comp(z) > 2)
			return (i);
		i++;
	}
	return (0);
}

void	mandelbrot(t_img *img)
{
	int			screen[W][H];
	t_vector	i;
	t_complex	z;
	t_complex	c;

	c.real = img->screen_begin.real;
	i.x = 0;
	while( i.x < W)
	{
		z.im = 0;
		z.real = 0;
		i.y = 0;
		c.im = img->screen_begin.im;
		while (i.y < H)
		{
			screen[i.x][i.y] = converge(img->iter_mult, z, c);
			c.im += img->percission;
			i.y++;
		}
		c.real += img->percission;
		i.x++;
	}
	print_screen(img, screen);
}
