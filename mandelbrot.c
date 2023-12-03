#include "fractol.h"

static int	converge(int iter_mult, t_complex c)
{
	t_complex	z;
	int			i;

	i = 0;
	z.real = 0;
	z.im = 0;
	while (i < abs(50 * iter_mult))
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
	t_vector	i;
	t_complex	c;
	int			color;
	int			offset;

	i.y = 0;
	i.x = 0;
	c.real = img->screen_begin.real;
	i.x = 0;
	while( i.x < W)
	{
		i.y = 0;
		c.im = img->screen_begin.im;
		while (i.y < H)
		{
			offset = (i.y * img->line_length + i.x * (img->bpp / 8));
			color = converge(img->iter_mult, c);
			color = creat_trgb(0, 0, (color * 4 + 10) %256, (color * 3 + 30) %256);
			*(unsigned int *)(img->addr + offset) = color;
			c.im += img->percission;
			i.y++;
		}
		c.real += img->percission;
		i.x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
