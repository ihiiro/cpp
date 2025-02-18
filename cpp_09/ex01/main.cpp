/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:08:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/18 07:09:55 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "ERROR: ./RPN \"<RPN expression\"" << std::endl;
		return 1;
	}

	if (argv == NULL)
	{
		std::cerr << "ERROR: FATAL: NULL ARGV" << std::endl;
		return 1;
	}

	if (*argv == NULL)
	{
		std::cerr << "ERROR: FATAL: NULL *ARGV" << std::endl;
		return 1;
	}

	/*  */
	for (int i = 1, prev = *argv[0]; *argv[i] != '\0'; i++)
	{
		if (not(prev >= '0' and prev <= '9' and *argv[i] == ' '))
		{
			std::cerr << "PARSE ERROR: rule D -> ' '" << std::endl;
			return 1;
		}
		if (not(prev == ' ' and (*argv[i] == '*' or *argv[i] == '/'
								or *argv[i] == '-' or *argv[i] == '+' 
								or (*argv[i] >= '0' and *argv[i] <= '9'))))
	}
	return 0;
}