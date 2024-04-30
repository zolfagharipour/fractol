/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:04:22 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/12/11 13:04:24 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	julia(t_img *img)
{
	t_vector	i;
	t_complex	z;
	int			color;
	int			offset;

	i.x = 0;
	z.real = img->screen_begin.real ;
	while (i.x < W)
	{
		i.y = 0;
		z.im = img->screen_begin.im;
		while (i.y < H)
		{
			offset = (i.y * img->line_length + i.x * (img->bpp / 8));
			color = converge(img->iter_mult, img->julia, z);
			color = log2(color) * 25;
			color = creat_rgb(img, color);
			*(unsigned int *)(img->addr + offset) = color;
			z.im -= img->percission;
			i.y++;
		}
		z.real += img->percission;
		i.x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
