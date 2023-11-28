#include <mlx.h>
#include <stdio.h>
#include <X11/keysym.h>
#include "../libft_math/libft_math.h"
#include <stdio.h>

# define W 800
# define H 450

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;


int	converge(t_complex z, t_complex c)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		z = ft_mult_comp(z, z);
		z = ft_add_comp(z, c);
		if (ft_size_comp(z) > 2)
			return (0);
		i++;
	}
	return (1);
}
void circle(t_data *img, void *mlx, void *mlx_win)
{
	int	y = 0;
	int x = 0;
	int color = 0;
	while (y < H * 4)
	{
		x = 0;
		while (x < W)
		{
			img->addr[y * W + x] = color;
			x++;
			color += 0x000000FF % 16;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}

void	print_screen(int screen[W][H * 4], t_data *img, void *mlx, void *mlx_win)
{
	t_vector	i;

	int x = 0;
	int y = 0;
	while (y < H * 4)
	{
		while (x < W)
		{
			img->addr[y * W + x] = 10;
			// if (screen[i.x][i.y])
			// 	img->addr[i.y * W + i.x] = 10;
			// else
			// 	img->addr[i.y * W + i.x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}

void fractol(t_data *img, void *mlx, void *mlx_win)
{
	int screen[W][H * 4];
	t_vector i;
	t_complex z;
	t_complex c;

	c.real = -2;
	i.y = 0;
	while (i.x < W)
	{
		z.im = 0;
		z.real = 0;
		i.y = 0;
		c.im = -1;
		while (i.y < H * 4)
		{
			screen[i.x][i.y] = converge(z, c);
			c.im += 0.03;
			i.y++;
		}
		c.real += 0.01;
		i.x++;
	}
	print_screen(screen, &img, mlx, mlx_win);
}


int main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, W, H, "FRACTOL");
	img.img = mlx_new_image(mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
printf("line_lenght%d\nbpp:%d\n", img.line_length, img.bpp);
	fractol (&img, mlx, mlx_win);
	

	mlx_loop(mlx);
}
