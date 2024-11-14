/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:09:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/13 18:20:57 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
	private:
		int fixed;
		static const int frac = 8;
	public:
		Fixed ();
		Fixed (const Fixed &f);
		Fixed& operator=(const Fixed &f);
		~Fixed ();

		int getRawBits () const;
		void setRawBits (int const raw);
};
