/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:56:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/22 16:37:09 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <list>
#include <vector>

#include <iostream>

int main()
{
	// doubly linked list
	std::list<int> li;
	li.push_back(0);
	li.push_back(1);
	li.push_back(2);
	try
	{
		std::cout << easyfind(li, 1) << std::endl;
		std::cout << easyfind(li, 2) << std::endl;
		std::cout << easyfind(li, 5) << std::endl;
	}
	catch (char const *e)
	{
		std::cout << "exception: " << e << std::endl;
	}
	// vector
	std::vector<int> v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(6);
	try
	{
		std::cout << easyfind(v, 2) << std::endl;
		std::cout << easyfind(v, 4) << std::endl;
		std::cout << easyfind(v, 6) << std::endl;
		std::cout << easyfind(v, -2) << std::endl;
	}
	catch (char const *e)
	{
		std::cout << "exception: " << e << std::endl;
	}
}