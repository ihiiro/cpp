/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:54:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 17:40:09 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "DOG: Default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "DOG: Destructor called" << std::endl;
}

Dog::Dog(const Dog &obj)
{
	brain = new Brain();
	if (this != &obj)
	{
		type = obj.type;
		*brain = *obj.brain;
	}
	else
		type = "Dog";
	std::cout << "DOG: Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
	if (this != &obj)
	{
		delete brain;
		brain = new Brain();
		*brain = *obj.brain;
		type = obj.type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << type << ": Woof!" << std::endl;
}