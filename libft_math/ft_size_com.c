#include "libft_math.h"

double	ft_size_comp(t_complex z)
{
	double	nbr;

	nbr = z.real * z.real + z.im * z.im;
	return (nbr);
}