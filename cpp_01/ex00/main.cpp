/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:38:47 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/06 16:49:31 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	Zombie *zombie = newZombie("zombie");
	randomChump("tempzombie");
	std::cout << "Heap zombie: " << zombie->get_name() << std::endl;
	delete zombie;
}