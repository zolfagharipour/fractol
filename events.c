#include "fractol.h"

static int	close_window(int keycode, t_img *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(EXIT_SUCCESS);
}

static int	keyboard(int keycode, t_img *img)
{
	if (keycode == XK_Escape)
		close_window(keycode, img);
	else if (keycode == XK_Left || keycode == XK_a)
		img->screen_begin.real -= img->percission * (W - 1) * 0.1;
	else if (keycode == XK_Right || keycode == XK_d)
		img->screen_begin.real += img->percission * (W - 1) * 0.1;
	else if (keycode == XK_Up || keycode == XK_w)
		img->screen_begin.im += img->percission * (H - 1) * 0.1;
	else if (keycode == XK_Down || keycode == XK_s)
		img->screen_begin.im -= img->percission * (H - 1) * 0.1;
	else if (keycode == XK_c)
		img->color++;
	else if (keycode == XK_r)
		fractal_init(img, img->ac, img->av);
	else if (keycode == XK_q)
		img->iter_mult *= 1.5;
	else if (keycode == XK_e)
		img->iter_mult *= 0.75;
	run_set(img);
}

static int	mouse(int button, int x, int y, t_img *img)
{
	if (button == 4)
	{
		img->screen_begin.real += x * 0.2 * img->percission;
		img->screen_begin.im -= y * 0.2 * img->percission;
		img->percission *= 0.8;
	}
	if (button == 5)
	{
		img->screen_begin.real -= x * 0.25 * img->percission;
		img->screen_begin.im += y * 0.25 * img->percission;
		img->percission *= 1.25;
	}
	run_set(img);
}

static int	mouse_track(int x, int y, t_img *img)
{
	img->julia.real = img->screen_begin.real + (img->percission * x);
	img->julia.im = img->screen_begin.im - (img->percission * y);
	run_set(img);
}

int	event_handler(t_img *img)
{
	mlx_hook(img->mlx_win, 2, 1L << 0, keyboard, img);
	mlx_hook(img->mlx_win, 17, 1L << 0, close_window, img);
	mlx_hook(img->mlx_win, 6, 1L << 8, mouse_track, img);
	mlx_hook(img->mlx_win, 4, 1L << 2, mouse, img);
	run_set(img);
}
