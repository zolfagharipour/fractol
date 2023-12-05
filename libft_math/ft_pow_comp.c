#include "libft_math.h"

t_complex	ft_pow_comp(t_complex z, int e)
{
	t_complex	nbr;
	double		tmp;

	nbr.real = z.real;
	nbr.im = z.im;
	while (e > 1)
	{
		tmp = nbr.real * z.real - nbr.im * z.im;
		nbr.im = nbr.real * z.im + nbr.im * z.real;
		nbr.real = tmp;
		e--;
	}
	return (nbr);
}
