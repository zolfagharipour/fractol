#include "libft_math.h"

double	ft_size_comp(t_complex z)
{
	double	nbr;

	nbr = pow(z.real, 2) + pow(z.im, 2);
	nbr = sqrt(nbr);
	return (nbr);
}