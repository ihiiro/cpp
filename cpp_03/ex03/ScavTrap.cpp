/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:36:39 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/11 12:49:14 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

void ScavTrap::guardGate()
{
	std::cout << "CHILD: ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap()
{
	hit_points = 99;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "CHILD SCAV: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string nm)
{
	(void)nm;
	hit_points = 99;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "CHILD SCAV: Copy constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_points != 0 && energy_points != 0)
	{
		energy_points--;
		std::cout << "CHILD: ScavTrap " << name << " attacks " << target
		<< " causing " << attack_damage << " points of damage!" << std::endl;
	}
}

ScavTrap::~ScavTrap()
{
	std::cout << "CHILD SCAV: Destructor called" << std::endl;
}