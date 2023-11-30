#include "main.h"

# define W 1700
# define H 1200

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
	while (i < 60)
	{
		z = ft_mult_comp(z, z);
		z = ft_add_comp(z, c);
		if (ft_size_comp(z) > 2)
			return (i);
		i++;
	}
	return (0);
}

void circle(int screen[W][H], t_data *img, void *mlx, void *mlx_win)
{
	int	y = 0;
	int x = 0;
	int color = 0;
	int offset;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			offset = (y * img->line_length + x * (img->bpp / 8));
				color = create_trgb(0, screen[x][y] * 8 + 10, screen[x][y] * 8 / 2, screen[x][y] * 7 + 30);
			*(unsigned int *)(img->addr + offset) = color;
			x++;
			color ++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}
void fractol(t_data *img, void *mlx, void *mlx_win)
{
	int screen[W][H];
	t_vector i;
	t_complex z;
	t_complex c;
	c.real = -2.3;
	i.x = 0;
	while (i.x < W)
	{
		z.im = 0;
		z.real = 0;
		i.y = 0;
		c.im = -1.3;
		while (i.y < H)
		{
			screen[i.x][i.y] = converge(z, c);
			c.im += 0.002;
			i.y++;
		}
		c.real += 0.002;
		i.x++;
	}
	circle (screen, img, mlx, mlx_win);
	printf("MANDELBROT SET IS GENERATED\n");
	// print_screen(screen, &img, mlx, mlx_win);
}
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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
	// circle (&img, mlx, mlx_win);
	

	mlx_loop(mlx);
}
