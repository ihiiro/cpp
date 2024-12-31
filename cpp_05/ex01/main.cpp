/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:12:22 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/31 20:14:10 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Form form("form", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	/*==================================*/
	try
	{
		Form form("form", 151, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	/*==================================*/
	try
	{
		Form form("form", 150, 150);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	/*==================================*/
	try
	{
		Form form("form", 1, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	/*==================================*/
	try
	{
		Form form("form", 50, 50);
		Bureaucrat bc(51, "bureaucrat");
		std::cout << form;
		bc.signForm(form);
		std::cout << form;
		form.beSigned(bc);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}