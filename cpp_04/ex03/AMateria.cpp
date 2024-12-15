/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:46:44 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/15 01:02:41 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

const std::string &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target) { (void)target; }

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type)
{
	(void)type;
}

AMateria::~AMateria()
{
}