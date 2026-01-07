/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:03:37 by rrichard          #+#    #+#             */
/*   Updated: 2026/01/07 15:07:23 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <exception>
#include <map>
#include <cctype>
#include "Fraction.hpp"

using PolyMap = std::map<int, double>;

void	start_calculations( PolyMap& poly );
void	first_degree( PolyMap& poly );
void	second_degree( PolyMap& poly );
void	print_step_value( const char* label, double v );
void	print_real( double x );

double	ft_sqrt( double x );
double	ft_abs( double x );
