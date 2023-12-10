#include "fractol.h"

int	creat_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	ft_atof(const char *nptr)
{
	int		i;
	double	result;
	int		sign;
	double	mult;

	sign = 1;
	result = 0;
	mult = 0;
	i = 0;

	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while ((nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '.')
	{
		if (nptr[i] != '.')
		{
			result *= mult;
			result += nptr[i] - 48;
		}
		else
			mult = 0.1;
		i++;
	}
	return (result * sign);
}
