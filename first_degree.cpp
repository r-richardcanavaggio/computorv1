/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_degree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:03:37 by rrichard          #+#    #+#             */
/*   Updated: 2026/01/07 11:33:09 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

void	first_degree( PolyMap& poly )
{
	double	res = 0.0;
	double	a = 0.0;
	double	b = 0.0;

	for (auto& i : poly)
	{
		if (i.first == 0)
			b = i.second;
		else
			a = i.second;
	}
	res = -b / a;
	if (res == 0.0)
		res = 0.0;
	Fraction	f(0, 1);
	if (double_to_fraction(res, f))
		std::cout << "The solution is:\n" << f << std::endl;
	else
		std::cout << "The solution is:\n" << res << std::endl;
}