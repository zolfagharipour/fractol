/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:05:00 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/12/11 13:05:01 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	f(t_complex x, t_complex lambda)
{
	t_complex	nbr;
	t_complex	poly[3];

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

static t_complex	df(t_complex x, t_complex lambda)
{
	t_complex	mult;
	t_complex	poly[2];

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

	nbr = pow(z.real - 1, 2) + pow(z.im, 2);
	nbr = sqrt(nbr);
	if (nbr < 0.001)
		return (1);
	nbr = pow(z.real + 1, 2) + pow(z.im, 2);
	nbr = sqrt(nbr);
	if (nbr < 0.001)
		return (2);
	nbr = pow(z.real, 2) + pow(z.im - 1, 2);
	nbr = sqrt(nbr);
	if (nbr < 0.001)
		return (3);
	return (0);
}

static int	root_finder(t_img *img, t_complex c)
{
	t_complex	z;
	t_complex	nbr;
	int			i;
	int			d;

	i = 0;
	nbr.real = -1;
	nbr.im = 0;
	while (i < 15 * img->iter_mult)
	{
		z = ft_dev_comp(f(c, img->lambda), df(c, img->lambda));
		z = ft_mult_comp(z, nbr);
		z = ft_add_comp(c, z);
		d = converge(z);
		c.real = z.real;
		c.im = z.im;
		i++;
	}
	if (d == 1)
		d = creat_trgb(0, 51, 51, 102);
	if (d == 2)
		d = creat_trgb(0, 153, 204, 255);
	if (d == 3)
		d = creat_trgb(0, 171, 62, 151);
	return (d);
}

void	newton(t_img *img)
{
	t_vector	i;
	t_complex	c;
	int			color;
	int			offset;

	i.x = 0;
	c.real = img->screen_begin.real ;
	while (i.x < W)
	{
		i.y = 0;
		c.im = img->screen_begin.im;
		while (i.y < H)
		{
			offset = (i.y * img->line_length + i.x * (img->bpp / 8));
			color = root_finder(img, c);
			*(unsigned int *)(img->addr + offset) = color;
			c.im -= img->percission;
			i.y++;
		}
		c.real += img->percission;
		i.x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
