/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult_comp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:06:10 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/12/11 13:06:11 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

t_complex	ft_mult_comp(t_complex z1, t_complex z2)
{
	t_complex	nbr;

	nbr.real = z1.real * z2.real - z1.im * z2.im;
	nbr.im = z1.real * z2.im + z1.im * z2.real;
	return (nbr);
}
