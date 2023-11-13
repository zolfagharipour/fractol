#include "libft_math.h"

double	ft_pow(double base, int power)
{
	double	nbr;

	nbr = 1;
	while (power > 0)
	{
		nbr *= base;
		power--;
	}
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (nbr);
}