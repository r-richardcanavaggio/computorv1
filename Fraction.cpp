/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fraction.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:59:27 by rrichard          #+#    #+#             */
/*   Updated: 2026/04/23 12:13:36 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fraction.hpp"
#include "computor.hpp"

Fraction::Fraction( int num, int den ) : numerator(num), denominator(den)
{
	if (denominator == 0)
		throw std::invalid_argument("Denominator cannot be zero");
	simplify();
}

void	Fraction::simplify()
{
	int	g = ft_gcd(ft_abs(numerator), ft_abs(denominator));

	numerator /= g;
	denominator /= g;
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
}

void	Fraction::print() const
{
	std::cout << numerator << "/" << denominator << std::endl;
}

std::ostream&	operator<<( std::ostream& os, const Fraction& f )
{
	os << f.numerator << "/" << f.denominator;
	return (os);
}

bool	double_to_fraction( double value, Fraction& out )
{
	int		maxDen    = 100;
	double	maxError  = 1e-6;
	bool	found     = false;
	double	bestError = 0.0;
	int		bestNum   = 0;
	int		bestDen   = 1;

	for (int den = 1; den <= maxDen; den++)
	{
		double	num_d = value * static_cast<double>(den);
		int		num   = round_to_int(num_d);
	
		double	approx = static_cast<double>(num) / static_cast<double>(den);
		double	err	   = ft_abs(approx - value);
		
		if (!found || err < bestError)
		{
			found     = true;
			bestError = err;
			bestNum   = num;
			bestDen   = den;
		}
	}
	if (!found || bestError > maxError || bestDen == 1)
		return (false);
	out = Fraction(bestNum, bestDen);
	return (true);
}