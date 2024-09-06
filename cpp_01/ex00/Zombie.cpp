/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:39:51 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/06 16:14:55 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void Zombie::announce()
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::get_name()
{
	return (name);
}

void Zombie::set_name(std::string nm)
{
	name = nm;
}

Zombie::~Zombie()
{
	std::cout << "DESTROYED: " << name << std::endl;
}