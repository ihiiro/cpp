/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:24:04 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/03 06:08:14 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int return_equivalent(std::string string)
{
	if (string == "DEBUG")
		return (0);
	if (string == "INFO")
		return (1);
	if (string == "WARNING")
		return (2);
	return (3);
}

int main(int argc, char **argv)
{
	Harl complainer;
	int equivalent;

	if (argc == 2)
	{
		equivalent = return_equivalent(argv[1]);
		switch (equivalent)
		{
			case 0:
				complainer.complain("DEBUG");
			case 1:
				complainer.complain("INFO");
			case 2:
				complainer.complain("WARNING");
			default:
				complainer.complain("ERROR");
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}