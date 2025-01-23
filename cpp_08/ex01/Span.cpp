/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:35:32 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/23 20:44:30 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span()
{
	max_size = 0;
}

Span::Span(unsigned int N)
{
	max_size = N;
}

Span::Span(Span const &span)
{
	max_size = span.max_size;
	li = span.li;
}

Span& Span::operator=(Span const &rhs_span)
{
	if (this != &rhs_span)
	{
		// possible memory leaks (test in main)
		max_size = rhs_span.max_size;
		li = rhs_span.li;
	}
	return *this;
}

Span::~Span()
{
	
}









void Span::addNumber(int i)
{
	if (li.size() + 1 > max_size)
		throw "Exception: addNumber(): container full;";
	li.push_back(i);
	li.sort();
}



struct IncGenerator
{
	int x;
	IncGenerator(int start): x(start){}
	int operator()() { return x++; }
};

void Span::addRange(int min, int max)
{
	if (min > max or (max - min + 1) + li.size() > max_size)
		throw "Exception: addRange(): min > max";
	std::list<int> li_(max - min + 1);
	IncGenerator g(min);
	std::generate(li_.begin(), li_.end(), g);
	li.merge(li_);
}





int Span::longestSpan()
{
	if (li.empty() or li.size() == 1)
		throw "Exception: shortestSpan(): 1 or no elements in container";
	int max = *std::max_element(li.begin(), li.end());
	int min = *std::min_element(li.begin(), li.end());

	return max - min;
}




int Span::shortestSpan()
{
	if (li.empty() or li.size() == 1)
		throw "Exception: shortestSpan(): 1 or no elements in container";
	std::list<int>::iterator start = li.begin();
	std::list<int>::iterator end = li.end();
	int smallest_diff = INT32_MAX;

	for (; start != end; start++)
	{
		std::list<int>::iterator real_start = start;
		if (++start != end and *start - *real_start < smallest_diff)
			smallest_diff = *start - *real_start;
		start = real_start;
	}
	return smallest_diff;
}

