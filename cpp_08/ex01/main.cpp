/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:35:30 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/24 02:45:18 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"



#include <iostream>

int main()
{
	Span sp(5);


	// adding numbers manually
	sp.addNumber(18);
	sp.addNumber(-7);


	// adding using a range
	try
	{
		sp.addRange(0, 3); // 4 + 2 = 6
	}
	catch (char const *e)
	{
		std::cout << "error: " << e << std::endl;
		sp.addRange(0, 1);
	}
	std::list<int>::iterator start = sp.li.begin();
	std::list<int>::iterator end = sp.li.end();

	std::cout << "\n\t\tcontainer elements:" << std::endl; 
	for (; start != end; start++)
		std::cout << "\t\t\t" << *start << std::endl;
	
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	
	std::cout << "==================================" << std::endl;
	Span span(1000001);
	span.addRange(1, 1000000);
	span.addNumber(INT32_MAX);
	// an attempt to add another number will throw an exception
	// because no more space is available in the container
	try
	{
		span.addNumber(-5);
	}
	catch (char const *)
	{
		std::cout << "no more space in container!" << std::endl;
	}
	

	start = span.li.begin();
	end = span.li.end();

	std::cout << "size: " << span.li.size() << std::endl;
	std::cout << "max: " << *std::max_element(start, end) << std::endl;
	std::cout << "min: " << *std::min_element(start, end) << std::endl;
	std::cout << "shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "longest span: " << span.longestSpan() << std::endl;
	std::cout << "==================================" << std::endl;
	Span empty_span;
	std::cout << "empty size: " << empty_span.max_size << std::endl;
	std::cout << "==================================" << std::endl;
	Span span1 = Span(5);
	span1.addNumber(6);
	span1.addNumber(3);
	span1.addNumber(17);
	span1.addNumber(9);
	span1.addNumber(11);
	std::cout << span1.shortestSpan() << std::endl;
	std::cout << span1.longestSpan() << std::endl;
}
