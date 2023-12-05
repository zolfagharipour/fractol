#include "libft_math.h"

t_complex	ft_dev_comp(t_complex z1, t_complex z2)
{
	t_complex	result;
	double		nbr_num;
	double		nbr_denom;

	nbr_num = z1.real * z2.real + z1.im * z2.im;
	nbr_denom = powf(z2.real, 2) + powf(z2.im, 2);
	result.real = nbr_num / nbr_denom;
	nbr_num = z1.im * z2.real - z1.real * z2.im;
	result.im = nbr_num / nbr_denom;
	return (result);
}