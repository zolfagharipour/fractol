#include "fractol.h"

void	run_set(t_img *img, char *name)
{
		if (!ft_strncmp(name, "mandel", ft_strlen(name)))
		{
			mandelbrot(img);
		}
		else if (!ft_strncmp(name, "julia", ft_strlen(name)))
		{
			julia(img);
		}
		else if (!ft_strncmp(name, "newton", ft_strlen(name)))
		{
			newton(img);
		}

}
int	close_window(int keycode,t_img *img)
{
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->mlx_win);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		exit(EXIT_SUCCESS);
}

int keyboard(int keycode, t_img *img)
{
	if (keycode == XK_Escape)
		close_window(keycode, img);
	else if (keycode == XK_Left)
		img->screen_begin.real -= img->percission * (W - 1) * 0.1;
	else if (keycode == XK_Right)
		img->screen_begin.real += img->percission * (W - 1) * 0.1;
	else if (keycode == XK_Up)
		img->screen_begin.im -= img->percission * (H - 1) * 0.1;
	else if (keycode == XK_Down)
		img->screen_begin.im += img->percission * (H - 1) * 0.1;
	else if (keycode == XK_a)
	{
		img->screen_begin.real -= img->percission * (W - 1) * 0.1;
		img->screen_begin.im -= img->percission * (H - 1) * 0.1;
		img->percission *= 1.25;
	}
	else if (keycode == XK_s)
	{
		img->screen_begin.real += img->percission * (W - 1) * 0.1;
		img->screen_begin.im += img->percission * (H - 1) * 0.1;
		img->percission /= 1.25;
	}
	else if (keycode == XK_q)
	{
		img->iter_mult *= 1.5;
		printf ("number of iteration: %d\n", abs(img->iter_mult * 10));
	}
	else if (keycode == XK_e)
	{
		img->iter_mult *= 0.75;
		printf ("number of iteration: %d\n", abs(img->iter_mult * 10));
	}
	run_set(img, "newton");

}

int	mouse(int button, int x, int y, t_img *img)
{
	if (button == 1)
	{
		img->julia.real = img->screen_begin.real + (img->percission * x);
		img->julia.im = img->screen_begin.im + (img->percission * y);
	}
	if (button == 4)
	{
		img->screen_begin.real += img->percission * (W - 1) * 0.1;
		img->screen_begin.im += img->percission * (H - 1) * 0.1;
		img->percission /= 1.25;
		printf("W: %f\tH: %f\n", img->percission * W, img->percission * H);

	}	
	if (button == 5)
	{
		img->screen_begin.real -= img->percission * (W - 1) * 0.1;
		img->screen_begin.im -= img->percission * (H - 1) * 0.1;
		img->percission *= 1.25;
		printf("W: %f\tH: %f\n", img->percission * W, img->percission * H);
	}
	run_set(img, "newton");

}
int	event_handler(t_img *img, char *name)
{
	mlx_hook(img->mlx_win, 2, 1L<<0, keyboard, img);
	mlx_hook(img->mlx_win, 17, 1L<<0, close_window, img);
	mlx_hook(img->mlx_win, 4, 1L<<2, mouse, img);
	run_set(img, name);
}
void	fractal_init(t_img *img)
{
	img->screen_begin.real = -2;
	img->screen_begin.im = -2;
	img->percission = 0.004;
	img->iter_mult = 1.0;
	img->julia.real = -0.8;
	img->julia.im = 0.156;
}

void	creat_img(char *name)
{
	t_img		img;

	fractal_init(&img);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, W, H, name);
	img.img = mlx_new_image(img.mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	XInitThreads();
	
	event_handler(&img, name);
	mlx_loop(img.mlx);
}

