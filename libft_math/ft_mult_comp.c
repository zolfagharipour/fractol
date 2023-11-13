#include "libft_math.h"

t_complex	ft_mult_comp(t_complex z1, t_complex z2)
{
	t_complex	nbr;

	nbr.real = z1.real * z2.real - z1.im *z2.im;
	nbr.im = z1.real * z2.im + z1.im * z2.real;
	return (nbr);
}