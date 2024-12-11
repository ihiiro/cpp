/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:54:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/11 16:35:06 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "DOG: Default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "DOG: Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << type << ": Woof!" << std::endl;
}