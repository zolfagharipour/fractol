/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:06:39 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/12/11 13:06:41 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MATH_H
# define LIBFT_MATH_H

# define PI 3.14159265359

# include <unistd.h>
# include <math.h>

typedef struct s_complex
{
	double	real;
	double	im;
}	t_complex;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

double		ft_abs(double nbr);
double		ft_pow(double base, int power);
double		ft_root(int base, int root);
double		ft_size_comp(t_complex z);

t_complex	ft_pow_comp(t_complex z, int e);
t_complex	ft_add_comp(t_complex z1, t_complex z2);
t_complex	ft_mult_comp(t_complex z1, t_complex z2);
t_complex	ft_dev_comp(t_complex z1, t_complex z2);

#endif
