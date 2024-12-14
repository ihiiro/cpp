/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:54:43 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 17:40:06 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "CAT: Default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "CAT: Destructor called" << std::endl;
}

Cat::Cat(const Cat &obj)
{
	brain = new Brain();
	if (this != &obj)
	{
		type = obj.type;
		*brain = *obj.brain;
	}
	else
		type = "Cat";
	std::cout << "CAT: Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
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

void Cat::makeSound() const
{
	std::cout << type << ": meow!" << std::endl;
}