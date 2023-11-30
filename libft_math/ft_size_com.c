#include "libft_math.h"

double	ft_size_comp(t_complex z)
{
	double	nbr;

	nbr = ft_pow(z.real, 2) + ft_pow(z.im, 2);
	nbr = sqrt(nbr);
	// nbr = ft_root(nbr, 2);
	return (nbr);
}