/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:48:20 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/09 23:09:41 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string nm, Weapon& wp) : weapon(wp), name(nm){}
