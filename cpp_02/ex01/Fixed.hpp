/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:09:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/18 17:16:22 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

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
		Fixed& operator= (const Fixed &f);

		// members
		int getRawBits () const;
		void setRawBits (int const raw);
		float toFloat () const;
		int toInt () const;

		~Fixed ();

		friend std::ostream& operator<< (std::ostream &out, Fixed const &fp);

};

