/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:04:13 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/12/11 13:04:14 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	run_set(t_img *img)
{
	if (!ft_strncmp(img->av[1], "mandelbrot", ft_strlen(img->av[1])))
	{
		mandelbrot(img);
	}
	else if (!ft_strncmp(img->av[1], "julia", ft_strlen(img->av[1])))
	{
		julia(img);
	}
	else if (!ft_strncmp(img->av[1], "newton", ft_strlen(img->av[1])))
	{
		newton(img);
	}
}

void	fractal_init(t_img *img, int ac, char **av)
{
	img->screen_begin.real = -2.2;
	img->screen_begin.im = 1.4;
	img->percission = 0.005;
	img->iter_mult = 1.0;
	img->av = av;
	img->ac = ac;
	img->lambda.real = 0;
	img->lambda.im = 1;
	img->color = 4;
	img->wing = 1;
	if (ac == 3 && !ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])))
		img->wing = ft_atoi(av[2]);
	if (ac > 3)
	{
		img->julia.real = atof(av[2]);
		img->julia.im = atof(av[3]);
	}
	else
	{
		img->julia.real = 0;
		img->julia.im = 0;
	}
}

void	creat_img(int ac, char **av)
{
	t_img		img;

	fractal_init(&img, ac, av);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, W, H, av[1]);
	img.img = mlx_new_image(img.mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.line_length, &img.endian);
	event_handler(&img);
	mlx_loop(img.mlx);
}
