#include "fractol.h"

static int	converge(int iter_mult, t_complex c, t_complex z)
{
	int			i;
	double		tmp;

	i = 0;
	while (i < 50 * abs(iter_mult))
	{
		tmp = z.real * z.real - z.im * z.im + c.real;
		z.im = c.im + (z.real * z.im + z.real * z.im);
		z.real = tmp;
		if (ft_size_comp(z) > 4)
			return (i);		
		i++;
	}
	return (0);
}

static void	draw_child(t_img *img, t_vector begin)
{
	t_vector	i;
	t_complex	z;
	int			color;
	int			offset;

	i.x = begin.x;
	z.real = img->screen_begin.real + (begin.x * img->percission);
	while( i.x <= begin.x + W / 10)
	{
		i.y = begin.y;
		z.im = img->screen_begin.im - (begin.y * img->percission);
		while (i.y <= begin.y + H / 10)
		{
			offset = (i.y * img->line_length + i.x * (img->bpp / 8));
			color = converge(img->iter_mult, img->julia, z);
			color = creat_trgb(0, (color * 4) + 20 %256, (color * 2) %256, (color * 3) +30 %256);
			*(unsigned int *)(img->addr + offset) = color;
			z.im -= img->percission;
			i.y++;
		}
		z.real += img->percission;
		i.x++;
	}
	exit (EXIT_SUCCESS);
}

void	julia(t_img *img)
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
