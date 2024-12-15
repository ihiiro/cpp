/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:50:06 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/15 01:01:17 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shots an " << type << " bolt at " << target.getName() << " *" << std::endl;
}

Ice::Ice()
{
	type = "ice";
	std::cout << "ICE: Default constructor called" << std::endl;
}

Ice::Ice(const Ice &obj)
{
	(void)obj;
	type = "ice";
	std::cout << "ICE: Copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &obj)
{
	(void)obj;
	return *this;
}

Ice::~Ice()
{
	std::cout << "ICE: Destructor called" << std::endl;
}