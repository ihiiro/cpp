/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:03:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/11 12:51:31 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		void highFivesGuys();
		FragTrap();
		FragTrap(std::string nm);
		~FragTrap();
		FragTrap(const FragTrap &obj);
		FragTrap& operator=(const FragTrap &obj);
};
