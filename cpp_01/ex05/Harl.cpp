/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:24:18 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/03 05:45:19 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	levels[0] = &Harl::debug;
	levels[1] = &Harl::info;
	levels[2] = &Harl::warning;
	levels[3] = &Harl::error;
}

void	Harl::debug()
{
	std::cout << "[DEBUG]\n" << DEBUG_MSG << std::endl;
}

void	Harl::info()
{
	std::cout << "[INFO]\n" << INFO_MSG << std::endl;
}

void	Harl::warning()
{
	std::cout << "[WARNING]\n" << WARNING_MSG << std::endl;
}

void	Harl::error()
{
	std::cout << "[ERROR]\n" << ERROR_MSG << std::endl;
}

void	Harl::complain(std::string level)
{
	if (level == "DEBUG")
		(this->*levels[0])();
	else if (level == "INFO")
		(this->*levels[1])();
	else if (level == "WARNING")
		(this->*levels[2])();
	else
		(this->*levels[3])();
}