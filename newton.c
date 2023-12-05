#include "fractol.h"


static t_complex	f(t_complex x)
{
	t_complex	lambda;
	t_complex	nbr;
	t_complex	poly[3];

	lambda.real = 0;
	lambda.im = 1;
	nbr.real = 1;
	nbr.im = 0;
	poly[0] = ft_add_comp(x, nbr);
	nbr.real = -1;
	poly[1] = ft_add_comp(x, nbr);
	lambda = ft_mult_comp(lambda, nbr);
	poly[2] = ft_add_comp(x, lambda);
	poly[0] = ft_mult_comp(ft_mult_comp(poly[0], poly[1]), poly[2]);
	return (poly[0]);
}

static t_complex	df(t_complex x)
{
	t_complex	lambda;
	t_complex	mult;
	t_complex	poly[2];

	lambda.real = 0;
	lambda.im = 1;
	mult.real = 3;
	mult.im = 0;

	poly[1] = ft_mult_comp(ft_pow_comp(x, 2), mult);
	mult.real = 2;
	poly[0] = ft_mult_comp(ft_mult_comp(x, mult), lambda);
	mult.real = -1;
	poly[0] = ft_mult_comp(poly[0], mult);
	poly[1] = ft_add_comp(ft_add_comp(poly[0], poly[1]), mult);

	return (poly[1]);
}

static int	converge(t_complex z)
{
	double		nbr;

	nbr = pow(z.real - 1, 2) + pow(z.im , 2);
	nbr = sqrt(nbr);
	if (nbr < 0.00000001)
		return (1);
	nbr = pow(z.real + 1, 2) + pow(z.im , 2);
	nbr = sqrt(nbr);
	if (nbr < 0.00000001)
		return (2);
	nbr = pow(z.real, 2) + pow(z.im - 1, 2);
	nbr = sqrt(nbr);
	if (nbr < 0.00000001)
		return (3);
	return (0);
}

static int	root_finder(int iter_mult, t_complex c)
{
	t_complex	z;
	t_complex	nbr;
	int			i;
	int			d;

	i = 0;
	nbr.real = -1;
	nbr.im = 0;
	while (i < 50 * abs(iter_mult))
	{
		z = ft_dev_comp(f(c), df(c));
		z = ft_mult_comp(z, nbr);
		z = ft_add_comp(c, z);
		d = converge(z);	
		c.real = z.real;
		c.im = z.im;
		i++;
	}
		if (d > 0)
			return (d);
	return (0);
}

static void	draw_child(t_img *img, t_vector begin)
{
	t_vector	i;
	t_complex	c;
	int			color;
	int			offset;

	i.x = begin.x;
	c.real = img->screen_begin.real + (begin.x * img->percission);
	while( i.x <= begin.x + W / 10)
	{
		i.y = begin.y;
		c.im = img->screen_begin.im + (begin.y * img->percission);
		while (i.y <= begin.y + H / 10)
		{
			offset = (i.y * img->line_length + i.x * (img->bpp / 8));
			color = root_finder(img->iter_mult, c);
			// color = creat_trgb(0, (color * 12) + 20 %256, (color * 4) %256, (color * 8) +30 %256);
			if (color == 1)
				color = creat_trgb(0, 30, 10, 100);
			if (color == 2)
				color = creat_trgb(0, 10, 100, 30);
			if (color == 3)
				color = creat_trgb(0, 100, 30, 10);
			*(unsigned int *)(img->addr + offset) = color;
			c.im += img->percission;
			i.y++;
		}
		c.real += img->percission;
		i.x++;
	}
	exit (EXIT_SUCCESS);
}

void	newton(t_img *img)
{
	t_vector	i;
	pid_t		pid[100];
	int			m;

	m = 0;
	i.x = 0;
	while (i.x <= W * 9 / 10)
	{
		i.y = 0;
		while (i.y <= H * 9/ 10)
		{
			pid[m] = fork();
			if (pid[m] == 0)
				draw_child(img, i);
			i.y += H / 10;
			m++;
		}
		i.x += W / 10;
	}

	m = 0;
	while (m < 100)
	{
		waitpid(pid[m], NULL, 0);
		m++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);

}
