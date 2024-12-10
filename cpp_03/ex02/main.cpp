/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:46:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/10 22:12:54 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap obj0;
	FragTrap obj1("idiot");

	obj0.attack("idiot");
	obj0.beRepaired(1);
	obj1.takeDamage(20);
	obj1.attack("sub-idiot");
	obj1.highFivesGuys();
}