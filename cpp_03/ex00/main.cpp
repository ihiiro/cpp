/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:46:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/10 21:11:32 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap obj0;
	ClapTrap obj1("idiot");

	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.beRepaired(1);
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj0.attack("idiot");
	obj1.takeDamage(9);
	obj1.attack("sub-idiot");
	obj1.attack("sub-idiot");
	obj1.attack("sub-idiot");
	obj1.attack("sub-idiot");
	obj1.attack("sub-idiot");
	obj1.attack("sub-idiot");
	obj1.attack("sub-idiot");
	obj1.attack("sub-idiot");
	obj1.attack("sub-idiot");
	obj1.attack("sub-idiot");
	obj1.attack("sub-idiot"); // 11th attack can't happen cuz energy points are 0
}