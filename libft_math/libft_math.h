#ifndef LIBFT_MATH_H
# define LIBFT_MATH_H

# define PI 3.14159265359

# include <unistd.h>
#include <math.h>


typedef struct s_complex {
	long double	real;
	long double	im;
} t_complex;

typedef struct s_vector {
	int	x;
	int	y;
} t_vector;


double	ft_abs(double nbr);
double	ft_pow(double base, int power);
double ft_root(int base, int root);
double	ft_size_comp(t_complex z);

t_complex	ft_add_comp(t_complex z1, t_complex z2);
t_complex	ft_mult_comp(t_complex z1, t_complex z2);


#endif