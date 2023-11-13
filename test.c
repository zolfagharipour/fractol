#include "libft_math/libft_math.h"
#include <stdio.h>

int	converge(t_complex z, t_complex c)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		z = ft_mult_comp(z, z);
		z = ft_add_comp(z, c);
		if (ft_size_comp(z) > 2)
			return (0);
		i++;
	}
	return (1);
}

void	print_screen(int screen[280][70])
{
	t_vector	i;

	i.x = 0;
	i.y = 0;
	while (i.y < 70)
	{
		while (i.x < 280)
		{
			if (screen[i.x][i.y])
			 	printf("%c", '*');
			else
				printf("%c", ' ');
			
			i.x++;
		}
		printf("\n");
		i.x = 0;
		i.y++;
	}
}

int main()
{
	int screen[280][70];
	t_vector i;
	t_complex z;
	t_complex c;

	c.real = -2;
	i.y = 0;
	while (i.x < 280)
	{
	z.im = 0;
	z.real = 0;
		i.y = 0;
		c.im = -1;
		while (i.y < 70)
		{
			screen[i.x][i.y] = converge(z, c);
			c.im += 0.03;
			i.y++;
		}
		c.real += 0.01;
		i.x++;
	}
	print_screen(screen);
}