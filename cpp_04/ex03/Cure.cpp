/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:50:09 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 18:38:53 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::Cure()
{
	type = "cure";
	std::cout << "CURE: Default constructor called" << std::endl;
}

Cure::Cure(const Cure &obj)
{
	// if (this != &obj)
	// 	type = obj.type;
	// else
	type = "cure";
	std::cout << "CURE: Copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &obj)
{
	// if (this != &obj)
	// 	type = obj.type;
	// type = "cure";
	return *this;
}

Cure::~Cure()
{
	std::cout << "CURE: Destructor called" << std::endl;
}