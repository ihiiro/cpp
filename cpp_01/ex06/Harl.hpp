/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:26:44 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/03 05:40:57 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!"
#define WARNING_MSG "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month."
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

class Harl
{
	void		debug();
	void		info();
	void		warning();
	void		error();
	typedef void (Harl::*arr)();
	arr levels[4];
	public:
	Harl();
	void	complain(std::string level);
};