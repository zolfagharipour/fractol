#include "fractol.h"

static void	info_print(void)
{
	write(1, "You should use one of the options below:\n-------\n\n", 50);
	write(1, "mandelbrot\n -(optional)number of wings\n\n", 40);
	write(1, "julia\n -(optional)dimension of initial Z\n\n", 42);
	write(1, "newton\n\n", 9);
	exit (EXIT_SUCCESS);
}

static int	error_check(int ac, char **av)
{
	if (ac == 1)
		info_print();
	else
	{
		if (!ft_strncmp("mandelbrot", av[1], ft_strlen(av[1])))
		{
			if (ac == 2 || atoi(av[2]) != 0)
				return (0);
			info_print();
		}
		if (!ft_strncmp("julia", av[1], ft_strlen(av[1])))
		{
			if (ac == 2)
				return (0);
			if (ac >= 4 && (ft_atof(av[2]) != 0 || ft_atof(av[3]) != 0))
				return (0);
			info_print();
		}
		if (!ft_strncmp("newton", av[1], ft_strlen(av[1])))
			return (0);
	}
	info_print();
}

int	main(int ac, char *av[])
{
	error_check(ac, av);
	creat_img(ac, av);
}
