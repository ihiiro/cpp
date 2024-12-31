/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:52:33 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 17:40:42 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &obj);
		Animal& operator=(const Animal &obj);
		virtual void makeSound() const = 0;
		std::string getType() const;
};