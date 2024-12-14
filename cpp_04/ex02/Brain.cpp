/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:32:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 00:01:04 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "BRAIN: Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "BRAIN: Destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &obj)
{
	if (this != &obj)
		for (int i = 0; i < 100; i++)
			ideas[i] = obj.ideas[i];
	return *this;
}
