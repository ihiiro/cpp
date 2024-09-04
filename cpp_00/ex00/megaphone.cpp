/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:30:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/03 19:33:12 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		size_t	len = std::strlen(argv[i]);
		for (size_t j = 0; j < len; j++)
			std::cout << (char)std::toupper(argv[i][j]);
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
}
