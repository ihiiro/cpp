/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:50:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 23:39:06 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <iostream>

class Cure: public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure &obj);
		Cure& operator=(const Cure &obj);
		Cure* clone() const;
		void use(ICharacter& target);
};