/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:46:44 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 18:14:06 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

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