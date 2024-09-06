/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:39:14 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/06 16:50:45 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class Zombie
{
	public:
		std::string name;
		Zombie();
		void announce(void);
};

Zombie *zombieHorde(int N, std::string name);