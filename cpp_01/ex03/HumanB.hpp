/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:48:35 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/09 23:18:22 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanB
{
	public:
		Weapon*  	weapon;
		std::string name;
		HumanB(std::string);
		void setWeapon(Weapon&);
		void attack();
};