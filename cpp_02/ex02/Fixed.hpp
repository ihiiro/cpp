/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:09:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/02 19:57:55 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

# define Q23_8_MIN -8388608
# define Q23_8_MAX 8388607

class Fixed
{
	private:
		int fixed;
		static const int frac;
	public:
		// constructors
		Fixed ();
		Fixed (int const i);
		Fixed (float const f);
		Fixed (const Fixed &f);		

		// overloads
		// assignment
		Fixed& operator= (const Fixed &f);
		// comparison
		bool operator> (const Fixed &f);
		bool operator< (const Fixed &f);
		bool operator>= (const Fixed &f);
		bool operator<= (const Fixed &f);
		bool operator== (const Fixed &f);
		bool operator!= (const Fixed &f);
		// arithmetic
		float operator+ (const Fixed &f);
		float operator- (const Fixed &f);
		float operator* (const Fixed &f);
		float operator/ (const Fixed &f);
		Fixed operator++ (int);
		Fixed& operator++ ();
		Fixed operator-- (int);
		Fixed& operator-- ();
		// min/max
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed& max(const Fixed& a, const Fixed& b);

		// members
		int getRawBits () const;
		void setRawBits (int const raw);
		float toFloat () const;
		int toInt () const;

		~Fixed ();
};

std::ostream& operator<< (std::ostream &out, Fixed const &fp);