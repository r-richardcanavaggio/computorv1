/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_degree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:03:37 by rrichard          #+#    #+#             */
/*   Updated: 2026/01/07 15:10:22 by rrichard         ###   ########.fr       */
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
		if (i.first == 0.0)
			b = i.second;
		else
			a = i.second;
	}
	res = -b / a;
	std::cout << "Unique solution of linear equation ax + b = 0 is -b / a\n";
	print_step_value("a = ", a);
	print_step_value("b = ", b);
	if (res == 0.0)
		res = 0.0;
	print_real(res);
	std::cout << std::endl;
}