/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:07:37 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 19:38:00 by yel-yaqi         ###   ########.fr       */
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
		if (materias[i])
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
		materias[i] = obj.materias[i];
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
			materias[i] = obj.materias[i];
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << "CHARACTER: Destructor called" << std::endl;
}