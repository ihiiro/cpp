/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:09:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/25 16:41:26 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void) 
{
	// on edge (vertex)
	std::cout << bsp(Point(7.2, 7.523), Point(11, 1), Point(9, 2), Point(9, 2)) << std::endl;
	std::cout << bsp(Point(7.2, 7.523), Point(11, 1), Point(9, 2), Point(11,1)) << std::endl;
	std::cout << bsp(Point(7.2, 7.523), Point(11, 1), Point(9, 2), Point(7.2, 7.523)) << std::endl;
	std::cout << bsp(Point(7.2, 7.523), Point(11, 1), Point(9, 2), Point(8,8)) << std::endl;
	// inside triangle
	std::cout << bsp(Point(2,3), Point(5,7), Point(8,2), Point(3,4)) << std::endl;
    return 0;
}
