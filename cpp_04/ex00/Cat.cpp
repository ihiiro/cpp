/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:54:43 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/11 16:34:49 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "CAT: Default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "CAT: Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << type << ": meow!" << std::endl;
}