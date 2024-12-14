/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:46:44 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 23:30:55 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

const std::string &AMateria::getType() const
{
	return type;
}

AMateria::AMateria()
{
	std::cout << "AMATERIA: Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMATERIA: Parameterized constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMATERIA: Destructor called" << std::endl;
}