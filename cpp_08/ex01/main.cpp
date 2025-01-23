/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:35:30 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/23 20:45:09 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"



#include <iostream>

int main()
{
	Span sp(4);

	sp.addRange(0, 3);

	std::list<int>::iterator start = sp.li.begin();
	std::list<int>::iterator end = sp.li.end();

	
	for (; start != end; start++)
		std::cout << *start << std::endl;
}
