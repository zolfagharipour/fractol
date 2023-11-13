#include "libft_math.h"

double ft_root(int base, int root)
{
	double	nbr;
	double	i;

	i = 0;
	while (i <= base)
	{
		if (ft_pow (i, root) >= ft_abs(base))
			return (i);
		i += 0.0000001;
	}

}
