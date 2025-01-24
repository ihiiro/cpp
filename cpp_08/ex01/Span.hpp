/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:35:34 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/24 01:32:15 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <list>
#include <algorithm>

class Span
{
	public:
		unsigned int max_size;
		std::list<int> li;


		Span();
		Span(unsigned int N);
		Span(Span const &span);
		Span& operator=(Span const &rhs_span);
		~Span();

		int shortestSpan();
		int longestSpan();

		void addNumber(int i);
		void addRange(int min, int max);
};