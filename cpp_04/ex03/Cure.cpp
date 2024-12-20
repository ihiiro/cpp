/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:50:09 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/15 01:04:02 by yel-yaqi         ###   ########.fr       */
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
}

Cure::Cure(const Cure &obj)
{
	(void)obj;
	type = "cure";
}

Cure& Cure::operator=(const Cure &obj)
{
	if (this != &obj)
		type = obj.type;
	return *this;
}

Cure::~Cure()
{
}