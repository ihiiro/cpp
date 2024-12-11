/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:54:49 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/11 16:49:06 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include <iostream>

class Cat: public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &obj);
		Cat& operator=(const Cat &obj);
		void makeSound() const;
};