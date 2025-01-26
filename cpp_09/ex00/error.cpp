/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:17:47 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/26 19:18:12 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void fatal_error(char const *str)
{
	std::cout << "FATAL ERROR: " << str << std::endl;
}

void usage_error(char const *str)
{
	std::cout << "USAGE ERROR: " << str << std::endl;
}

void stupidity_error(char const *str)
{
	std::cout << "STUPIDITY ERROR: " << str << std::endl;
}