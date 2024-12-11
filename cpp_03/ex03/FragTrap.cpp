/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:06:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/11 12:50:37 by yel-yaqi         ###   ########.fr       */
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
	hit_points = 100;
	attack_damage = 30;
	std::cout << "CHILD FRAG: Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string nm)
{
	(void)nm;
	hit_points = 100;
	attack_damage = 30;
	std::cout << "CHILD FRAG: Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "CHILD FRAG: Destructor called" << std::endl;
}
