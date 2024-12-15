/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:44:36 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/15 01:33:39 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (!materias[i])
		{
			materias[i] = m;
			break;
		}
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (materias[i] and materias[i]->getType() == type)
		{
			if (type == "cure")
				return new Cure();
			else if (type == "ice")
				return new Ice();
		}
	return NULL;
}

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	for (int i = 0; i < 4; i++)
		materias[i] = obj.materias[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
	if (this != &obj)
		for (int i = 0; i < 4; i++)
			materias[i] = obj.materias[i];
	return *this;
}

MateriaSource::~MateriaSource()
{
	
}