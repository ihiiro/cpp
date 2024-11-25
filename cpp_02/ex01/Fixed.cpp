/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:09:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/25 16:49:11 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <math.h>

int const Fixed::frac = 8;

double poww(double base, double exp)
{
	double pow = 1;
	if (exp == 0)
		return 1;
	if (exp < 0)
	{
		exp *= -1;
		base = 1 / base;
	}
	if (exp == 1)
		return (base);
	while (exp != 0)
	{
		pow *= base;
		exp = exp - 1;
	}
	return pow;
}

Fixed::Fixed()
{
	fixed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	if (this == &f)
		this->fixed = 0;
	else
		*this = f;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &f)
{
	if (this != &f)
		this->fixed = f.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed;
}

void Fixed::setRawBits(int const raw)
{
	fixed = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

Fixed::Fixed(int const i)
{
	std::cout << "Int constructor called" << std::endl;
	fixed = i << frac;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	fixed = roundf(f * poww(2, frac));
}

float Fixed::toFloat() const
{
	return (fixed * poww(2, -frac));
}

int Fixed::toInt() const
{
	return (fixed >> frac);
}

std::ostream& operator<< (std::ostream &out, Fixed const &fp)
{
	out << fp.toFloat();
	return (out);
}
