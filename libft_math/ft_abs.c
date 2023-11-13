#include "libft_math.h"

double	ft_abs(double nbr)
{
	if (nbr == -2147483648)
		return (0);
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}