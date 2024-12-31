/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:12:22 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/31 13:02:11 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bc(-1, "p");
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bc(222, "named");
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bc(150, "slickback");
		bc.dec();
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bc(1, "slickback");
		bc.inc();
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	Bureaucrat bc(1, "wower");

	bc.dec();
	std::cout << bc << std::endl;
	bc.inc();
	std::cout << bc << std::endl;
}