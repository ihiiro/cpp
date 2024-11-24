/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:09:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/24 20:10:17 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a = Fixed(0.00390625f);
	Fixed  b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl; // 0
	std::cout << --a << std::endl; // 0.00390625
	std::cout << a << std::endl; // 0.00390625
	std::cout << a-- << std::endl; // 0.00390625
	std::cout << a << std::endl; // 0.0078125
	std::cout << b << std::endl; // 10.1016
	// std::cout << Fixed::max( a, b * Fixed(-1) ) << std::endl; // 10.1016

	// min
	// / + -
	return 0;
}
