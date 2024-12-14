/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:50:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 18:23:15 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <iostream>

class Ice: public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice &obj);
		Ice& operator=(const Ice &obj);
		Ice* clone() const;
		void use(ICharacter& target);
};