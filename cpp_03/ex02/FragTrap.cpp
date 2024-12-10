/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:06:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/10 22:11:30 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

void FragTrap::highFivesGuys()
{
	std::cout << "CHILD FRAG: FragTrap " << name << " is giving you a high five!" << std::endl;
}

FragTrap::FragTrap()
{
	name = "sub-idiot";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "CHILD FRAG: Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string nm)
{
	name = nm;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "CHILD FRAG: Copy constructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (hit_points != 0 && energy_points != 0)
	{
		energy_points--;
		std::cout << "CHILD FRAG: FragTrap " << name << " attacks " << target
		<< " causing " << attack_damage << " points of damage!" << std::endl;
	}
}

FragTrap::~FragTrap()
{
	std::cout << "CHILD FRAG: Destructor called" << std::endl;
}
