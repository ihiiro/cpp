/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:47:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/08 16:51:56 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType() const
{
	return (type);
}

void Weapon::setType(std::string new_type)
{
	type = new_type;
}

Weapon::Weapon(std::string type)
{
	setType(type);
}