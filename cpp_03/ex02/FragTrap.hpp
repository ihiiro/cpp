/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:03:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/10 22:05:27 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		void highFivesGuys();
		FragTrap();
		FragTrap(std::string nm);
		~FragTrap();
		FragTrap(const FragTrap &obj);
		FragTrap& operator=(const FragTrap &obj);
		void attack(const std::string& target);
};
