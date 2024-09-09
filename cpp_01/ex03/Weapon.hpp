/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:47:35 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/08 16:59:21 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string);
		const std::string& getType() const;
		void		setType(std::string new_type);
};