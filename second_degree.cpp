/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_degree.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:36:40 by rrichard          #+#    #+#             */
/*   Updated: 2026/01/07 12:42:39 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

static void	print_real( double x )
{
	Fraction f(0, 1);

	if (x == 0.0)
		x = 0.0;
	if (double_to_fraction(x, f))
		std::cout << f;
	else
		std::cout << x;
}

void	print_complex( double re, double im )
{
	const double	eps = 1e-9;

	auto near = [&](double x, double target)
	{
		return (ft_abs(x - target) < eps);
	};

	if (ft_abs(im) < eps)
	{
		print_real(re);
		std::cout << std::endl;
		return ;
	}
	if (ft_abs(re) < eps)
	{
		if (near(im, 1))
			std::cout << "i";
		else if (near(im, -1))
			std::cout << "-i";
		else
		{
			print_real(im);
			std::cout << "i";
		}
		std::cout << std::endl;
		return ;
	}
	print_real(re);
	std::cout << " ";
	if (near(im, 1))
		std::cout << "+ i";
	else if (near(im, -1))
		std::cout << " - i";
	else if (im > 0)
	{
		std::cout << "+ ";
		print_real(im);
		std::cout << "i";
	}
	else
	{
		std::cout << "- ";
		print_real(-im);
		std::cout << "i";
	}
	std::cout << std::endl;
}

void	second_degree( PolyMap& poly )
{
	double	a = 0.0, b = 0.0, c = 0.0, det = 0.0;

	for (auto& i : poly)
	{
		if (i.first == 0)
			c = i.second;
		else if (i.first == 1)
			b = i.second;
		else
			a = i.second;
	}
	det = b * b - 4.0 * a * c;
	if (ft_abs(det) < 1e-12)
	{
		Fraction	f(0, 1);
		double		res = -b / (2 * a);
		
		std::cout << "The solution is:" << std::endl;
		print_real(res);
		std::cout << std::endl;
	}
	else if (det > 0.0)
	{
		double root1 = 0.0, root2 = 0.0;

		root1 = (-b - ft_sqrt(det)) / (2 * a);
		root2 = (-b + ft_sqrt(det)) / (2 * a);
		Fraction f1(0, 1);
		Fraction f2(0, 1);
		std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;
		print_real(root1);
		std::cout << std::endl;
		print_real(root2);
		std::cout << std::endl;
	}
	else if (det < 0.0)
	{
		double	real_root = 0.0, imag_root = 0.0;

		if (b != 0.0)
			real_root = -b / (2 * a);
		imag_root = ft_sqrt(-det) / (2 * a);
		std::cout << "Discriminant is strictly negative, the two complex solutions are:" << std::endl;
		print_complex(real_root, imag_root);
		print_complex(real_root, -imag_root);
	}
}