#include "fractol.h"

int main(int ac, char *av[])
{
	t_img img;
	if (ac == 1)
		write (1, "Input is required.\n", 19);
	else
	{
		creat_img (av[1]);
	}
}