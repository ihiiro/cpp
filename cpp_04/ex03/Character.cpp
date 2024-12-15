/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:07:37 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/15 01:00:15 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

const std::string& Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	/* free unequipped */
	for (int i = 0; i < 4; i++)
	{
		delete unequipped[i];
		unequipped[i] = NULL;
	}
	/* equip new materia */
	for (int i = 0; i < 4; i++)
		if (!materias[i])
		{
			materias[i] = m;
			return;
		}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		unequipped[idx] = materias[idx];
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
		materias[idx]->use(target);
}

Character::Character()
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL, unequipped[i] = NULL;
	std::cout << "CHARACTER: Default constructor called" << std::endl;
}

Character::Character(const Character &obj)
{
	for (int i = 0; i < 4; i++)
	{
		delete materias[i];
		if (obj.materias[i]->getType() == "cure")
			materias[i] = new Cure();
		else if (obj.materias[i]->getType() == "ice")
			materias[i] = new Ice();
		// *materias[i] = *obj.materias[i];
	}
	std::cout << "CHARACTER: Copy constructor called" << std::endl;
}

Character& Character::operator=(const Character &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			delete materias[i];
			if (obj.materias[i]->getType() == "cure")
				materias[i] = new Cure();
			else if (obj.materias[i]->getType() == "ice")
				materias[i] = new Ice();
			// *materias[i] = *obj.materias[i];
		}
	}
	return *this;
}

Character::Character(std::string nm)
{
	name = nm;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete materias[i], delete unequipped[i];
	std::cout << "CHARACTER: Destructor called" << std::endl;
}