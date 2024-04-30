/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_com.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:06:28 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/12/11 13:06:30 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

double	ft_size_comp(t_complex z)
{
	double	nbr;

	nbr = z.real * z.real + z.im * z.im;
	return (nbr);
}
