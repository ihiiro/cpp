/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:22:29 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/18 15:00:07 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
	o << rhs.get(); return o;
}

template <typename T>
void print( T const & x )
{
	std::cout << x << std::endl; 
}

int main()
{
	char  x[] = "heeeeeeeeeeeeeey";
	Awesome tab2[5];
	iter( x, 16, print ); // implicit instantiation
	iter( tab2, 5, print<Awesome> ); // explicit instantiation
	return 0;
}