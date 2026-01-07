/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:31:20 by rrichard          #+#    #+#             */
/*   Updated: 2026/01/07 15:33:35 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

int	round_to_int( double x )
{
	if (x >= 0.0)
		return (static_cast<int>(x + 0.5));
	return (static_cast<int>(x - 0.5));
}

double	ft_abs( double x )
{
	return (x > 0 ? x : -x);
}

double	ft_round( double x )
{
	if (x >= 0.0)
		return (static_cast<long long>(x + 0.5));
	return (static_cast<long long>(x - 0.5));
}

int	ft_gcd( int a, int b )
{
	if (b == 0)
		return (a);
	return (ft_gcd(b, a % b));
}

double	ft_sqrt( double x )
{
	if (x < 0.0)
		throw std::runtime_error("ft_sqrt: negative input");
	if (x == 0.0)
		return (0.0);

	double			guess = (x >= 1.0) ? (x / 2.0) : 1.0;
	const double	tolerance = 1e-9;

	while (true)
	{
		double	other_side = x / guess;
		double	new_guess = (guess + other_side) / 2.0;

		double	diff = ft_abs(guess - new_guess);

		if (diff < tolerance)
		{
			double r = ft_round(new_guess);
			if (ft_abs(new_guess - r) < tolerance)
				return (r);
			return (new_guess);
		}
		guess = new_guess;
	}
}