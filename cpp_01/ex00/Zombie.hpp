/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:39:14 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/06 16:07:23 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class Zombie
{
	private:
		std::string name;
	public:
		~Zombie();
		void announce(void);
		std::string get_name();
		void   		set_name(std::string nm);
};

Zombie *newZombie(std::string name);

void randomChump(std::string name);