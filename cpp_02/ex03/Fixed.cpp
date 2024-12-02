/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:09:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/02 20:15:31 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <math.h>
#include <stdbool.h>

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
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	if (this == &f)
		this->fixed = 0;
	else
		*this = f;
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return fixed;
}

void Fixed::setRawBits(int const raw)
{
	fixed = raw;
	// std::cout << "setRawBits member function called" << std::endl;
}

Fixed::Fixed(int const i)
{
	// std::cout << "Int constructor called" << std::endl;
	if (i > Q23_8_MAX)
		fixed = roundf(Q23_8_MAX * poww(2, frac));
	else if (i < Q23_8_MIN)
		fixed = Q23_8_MIN * poww(2, frac);
	else
		fixed = i << frac;
}

Fixed::Fixed(float const f)
{
	// std::cout << "Float constructor called" << std::endl;
	if (f > Q23_8_MAX)
		fixed = roundf(Q23_8_MAX * poww(2, frac));
	else if (f < Q23_8_MIN)
		fixed = Q23_8_MIN * poww(2, frac);
	else
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

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.fixed < b.fixed)
		return a;
	return b;
}

Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.fixed < b.fixed)
		return (Fixed&)a;
	return (Fixed&)b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.fixed > b.fixed)
		return a;
	return b;
}

Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.fixed > b.fixed)
		return (Fixed&)a;
	return (Fixed&)b;
}

/* STREAM INSERTION OVERLOAD */

std::ostream& operator<< (std::ostream &out, Fixed const &fp)
{
	out << fp.toFloat();
	return (out);
}

/* COPY ASSIGNMENT OVERLOAD */

Fixed& Fixed::operator=(const Fixed &f)
{
	if (this != &f)
		this->fixed = f.getRawBits();
	// std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

/* COMPARISON OVERLOADS */

bool Fixed::operator> (const Fixed &f)
{
	bool greater_than;

	greater_than = this->fixed > f.fixed;
	return (greater_than);
}

bool Fixed::operator< (const Fixed &f)
{
	bool less_than;

	less_than = this->fixed < f.fixed;
	return (less_than);
}

bool Fixed::operator>= (const Fixed &f)
{
	bool greater_than_or_equal;

	greater_than_or_equal = this->fixed >= f.fixed;
	return (greater_than_or_equal);
}

bool Fixed::operator<= (const Fixed &f)
{
	bool less_than_or_equal;

	less_than_or_equal = this->fixed <= f.fixed;
	return (less_than_or_equal);
}

bool Fixed::operator== (const Fixed &f)
{
	bool equal;

	equal = this->fixed == f.fixed;
	return (equal);
}

bool Fixed::operator!= (const Fixed &f)
{
	bool not_equal;

	not_equal = this->fixed != f.fixed;
	return (not_equal);
}

/* ARITHMETIC OVERLOADS */

float Fixed::operator+ (const Fixed &f)
{
	return this->toFloat() + f.toFloat();
}

float Fixed::operator- (const Fixed &f)
{
	return this->toFloat() - f.toFloat();
}

float Fixed::operator* (const Fixed &f)
{
	return this->toFloat() * f.toFloat();
}

float Fixed::operator/ (const Fixed &f)
{
	return this->toFloat() / f.toFloat();
}

/* INCREMENT/DECREMENT OVERLOADS */

Fixed Fixed::operator++ (int)
{
	Fixed pre = *this;
	this->fixed++;
	return pre;
}

Fixed& Fixed::operator++ ()
{
	(*this)++;
	return *this;
}

Fixed Fixed::operator-- (int)
{
	Fixed pre = *this;
	this->fixed--;
	return pre;
}

Fixed& Fixed::operator-- ()
{
	(*this)--;
	return *this;
}