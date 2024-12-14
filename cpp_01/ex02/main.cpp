/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:53:43 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/14 21:44:59 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *str_ptr = &str;

	std::string& str_ref = str;

	/* addresses */
	std::cout << "str: ";
	std::cout << std::setw(24) << &str << std::endl;

	std::cout << "str_ptr: ";
	std::cout << std::setw(20) << str_ptr << std::endl;

	std::cout << "str_ref: ";
	std::cout << std::setw(20) << &str_ref << std::endl << std::endl;

	/* values */
	std::cout << "str: ";
	std::cout << std::setw(26) << str << std::endl;

	std::cout << "str_ptr: ";
	std::cout << std::setw(22) << *str_ptr << std::endl;

	std::cout << "str_ref: ";
	std::cout << std::setw(22) << str_ref << std::endl;
}