/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:13:22 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/11 17:00:59 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WRONG CAT: Default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WRONG CAT: Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << type << ": aaaaaaaa" << std::endl;
}