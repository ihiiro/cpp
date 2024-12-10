/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:46:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/10 21:46:16 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap obj0;
	ScavTrap obj1("idiot");

	obj0.attack("idiot");
	obj0.beRepaired(1);
	obj1.takeDamage(20);
	obj1.attack("sub-idiot");
	obj0.guardGate();
}