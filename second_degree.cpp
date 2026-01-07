/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_degree.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:36:40 by rrichard          #+#    #+#             */
/*   Updated: 2026/01/07 15:07:17 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

void	print_real( double x )
{
	Fraction f(0, 1);

	if (x == 0.0)
		x = 0.0;
	if (double_to_fraction(x, f))
		std::cout << f;
	else
		std::cout << x;
}

void	print_step_value( const char* label, double v )
{
	std::cout << label;
	print_real(v);
	std::cout << std::endl;
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
		if (i.first == 0.0)
			c = i.second;
		else if (i.first == 1.0)
			b = i.second;
		else
			a = i.second;
	}

	std::cout << "To resolve quadratic equations, we need the determinant ∆ = b^2 - 4ac\n";
	print_step_value("a = ", a);
	print_step_value("b = ", b);
	print_step_value("c = ", c);

	det = b * b - 4. * a * c;
	std::cout << "∆ = " << b << "^2 - 4 * " << a << " * " << c <<"\n";
	print_step_value("∆ = ", det);
	
	const double	denom = 2. * a;
	print_step_value("2a = ", denom);

	if (ft_abs(det) < 1e-12)
	{
		std::cout << "For ∆ = 0, only one solution exists: -b / (2a)\n";
		const double		res = -b / denom;
		
		std::cout << "The solution is:" << std::endl;
		std::cout << -b << " / " << denom << " = ";
		print_real(res);
		std::cout << std::endl;
	}
	else if (det > 0.0)
	{
		std::cout << "For ∆ > 0, two real solutions exists: (-b ± √(∆))/(2a)\n";
		const double	sqrt_det = ft_sqrt(det);
		print_step_value("√(∆) = ", sqrt_det);

		const double	root1 = (-b - sqrt_det) / denom;
		const double	root2 = (-b + sqrt_det) / denom;

		std::cout << "The two real solutions are:" << std::endl;
		std::cout << "(" << -b << " - " << sqrt_det << ") / " << denom << " = ";
		print_real(root1);
		std::cout << std::endl;
		std::cout << "(" << -b << " + " << sqrt_det << ") / " << denom << " = ";
		print_real(root2);
		std::cout << std::endl;
	}
	else if (det < 0.0)
	{
		std::cout << "For ∆ < 0, two complex solutions exists: (-b ± i√(-∆))/(2a)\n";
		const double	sqrt_neg_det = ft_sqrt(-det);
		print_step_value("√(-∆) = ", sqrt_neg_det);

		const double	real_root = -b / denom;
		const double	imag_root = sqrt_neg_det / denom;

		std::cout << "The two complex solutions are:" << std::endl;
		std::cout << "(" << -b << " - " << sqrt_neg_det << "i) / " << denom << " = ";
		print_complex(real_root, -imag_root);
		std::cout << "(" << -b << " + " << sqrt_neg_det << "i) / " << denom << " = ";
		print_complex(real_root, imag_root);
	}
}