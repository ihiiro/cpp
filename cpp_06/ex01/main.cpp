/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:42:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/11 00:49:02 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data x = {1,12,2};

	Data *y = Serializer::deserialize(Serializer::serialize(&x));

	std::cout << y->x << std::endl;
	std::cout << y->y << std::endl;
	std::cout << y->z << std::endl;
	std::cout << y << std::endl;
	std::cout << &x << std::endl;
}