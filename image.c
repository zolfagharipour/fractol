#include "fractol.h"

void	run_set(t_img *img, char *name)
{
		if (!ft_strncmp(name, "mandel", ft_strlen(name)))
		{
			mandelbrot(img);
		}
		else if (!ft_strncmp(name, "julia", ft_strlen(name)))
		{
			// JULIA
		}
		else if (!ft_strncmp(name, "newton", ft_strlen(name)))
		{
			// NEWTON
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
	printf("Key: %d\n", keycode);
	if (keycode == XK_Escape)
		close_window(keycode, img);
	else if (keycode == XK_Left)
		img->screen_begin.real *= 0.9;
	else if (keycode == XK_Right)
		img->screen_begin.real *= 1.1;
	else if (keycode == XK_Up)
		img->screen_begin.im *= 0.9;
	else if (keycode == XK_Down)
		img->screen_begin.im *= 1.1;
	else if (keycode == 97)
	{
		// img->screen_begin.real *= 0.8;
		// img->screen_begin.im *= 0.8;
		img->percission *= 0.8;
	}
	else if (keycode == XK_i)
	{
		img->iter_mult *= 1.5;
	}
	run_set(img, "mandel");

}

int	mouse(int button, int x, int y, t_img *img)
{
	printf("button: %d\n", button);
	// if (button ==  )
}
int	event_handler(t_img *img, char *name)
{
	mlx_hook(img->mlx_win, 2, 1L<<0, keyboard, img);
	mlx_hook(img->mlx_win, 17, 1L<<0, close_window, img);
	run_set(img, name);
}
void	fractal_init(t_img *img)
{
	img->screen_begin.real = -2.2;
	img->screen_begin.im = -1.2;
	img->percission = 0.003;
	img->iter_mult = 1.0;
}

void	creat_img(char *name)
{
	t_img		img;

	fractal_init(&img);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, W, H, name);
	img.img = mlx_new_image(img.mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	
	event_handler(&img, name);
	mlx_loop(img.mlx);
}

