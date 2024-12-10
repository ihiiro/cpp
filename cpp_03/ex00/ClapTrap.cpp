/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:46:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/10 21:02:44 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	name = "sub-idiot";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string nm)
{
	name = nm;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "Copy constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_points != 0 && energy_points != 0)
	{
		energy_points--;
		std::cout << "ClapTrap " << name << " attacks " << target
		<< " causing " << attack_damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit_points -= amount;
	std::cout << "ClapTrap " << name << " got attacked by someone (probably sub-idiot) and lost "
	<< amount << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points != 0 && energy_points != 0)
	{
		hit_points += amount;
		energy_points--;
		std::cout << "ClapTrap " << name << " repaired and gained "
		<< amount << " hit points" << std::endl;
	}
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}