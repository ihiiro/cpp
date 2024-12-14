/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:54:49 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 17:37:37 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat: public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &obj);
		Cat& operator=(const Cat &obj);
		~Cat();
		void makeSound() const;
		void pure_virtual_function();
};