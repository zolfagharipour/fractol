/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:04:49 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/12/11 13:04:51 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	wings(int wing, t_complex z)
{
	t_complex	z1;
	int			i;
	double		tmp;

	i = 0;
	z1.real = z.real;
	z1.im = z.im;
	while (i < wing)
	{
		tmp = z1.real * z.real - z1.im * z.im;
		z.im = (z1.real * z.im + z.real * z1.im);
		z.real = tmp;
		i++;
	}
	return (z);
}

static int	converge(int iter_mult, t_complex c, int wing)
{
	t_complex	z;
	int			i;

	i = 0;
	z.real = 0;
	z.im = 0;
	while (i < 50 * iter_mult)
	{
		z = wings(wing, z);
		z.real += c.real;
		z.im += c.im;
		if (ft_size_comp(z) > 4)
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

	i.x = 0;
	c.real = img->screen_begin.real;
	while (i.x < W)
	{
		i.y = 0;
		c.im = img->screen_begin.im;
		while (i.y < H)
		{
			offset = (i.y * img->line_length + i.x * (img->bpp / 8));
			color = converge(img->iter_mult, c, img->wing);
			color = log2(color) * 25;
			color = creat_rgb(img, color);
			*(unsigned int *)(img->addr + offset) = color;
			c.im -= img->percission;
			i.y++;
		}
		c.real += img->percission;
		i.x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
