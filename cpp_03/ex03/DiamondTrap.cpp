/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:33:02 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/11 12:36:38 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
	name = "diamond-sub-idiot";
	hit_points = DiamondTrap::FragTrap::hit_points;
	energy_points = DiamondTrap::ScavTrap::energy_points;
	attack_damage = DiamondTrap::FragTrap::attack_damage;
	std::cout << "MONSTER: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string nm)
{
	name = nm;
	ClapTrap::name = name + "_" + ClapTrap::name;
	hit_points = DiamondTrap::FragTrap::hit_points;
	energy_points = DiamondTrap::ScavTrap::energy_points;
	attack_damage = DiamondTrap::FragTrap::attack_damage;
	std::cout << "MONSTER: Copy constructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "MONSTER: I am " << ClapTrap::name << std::endl;
	std::cout << "Name=" << name << std::endl;
	std::cout << "ClapTrap::name=" << ClapTrap::name << std::endl;
	std::cout << "hit_points=" << hit_points << std::endl;
	std::cout << "energy_points=" << energy_points << std::endl;
	std::cout << "attack_damage=" << attack_damage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "MONSTER: Destructor called" << std::endl;
}
