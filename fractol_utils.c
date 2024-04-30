/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:04:03 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/12/11 13:04:05 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	creat_rgb(t_img *img, int color)
{
	int	r;
	int	g;
	int	b;

	r = (color * (img->color % 7) + 20) % 256;
	g = (color * (img->color % 3)) % 256;
	b = (color * (img->color % 5) + 30) % 256;
	return (r << 16 | g << 8 | b);
}

int	creat_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static double	atof_helper(const char *nptr, int i)
{
	double	mult;
	double	result;

	result = 0;
	mult = 10;
	while ((nptr[i] != '\0' && nptr[i] >= '0'
			&& nptr[i] <= '9') || nptr[i] == '.')
	{
		if (nptr[i] != '.')
		{
			result *= mult;
			result += nptr[i] - 48;
		}
		else
			mult = 0.1;
		i++;
	}
	return (result);
}

double	ft_atof(const char *nptr)
{
	int		i;
	double	result;
	int		sign;

	sign = 1;
	i = 0;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	result = atof_helper(nptr, i);
	return (result * sign);
}
