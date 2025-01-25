/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:01:11 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/25 19:34:22 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template <typename T, typename container=std::deque<T> >
class MutantStack: public std::stack<T>
{
	public:

		typedef typename container::iterator iterator;


		
		MutantStack()
		{
			
		}

		
		~MutantStack()
		{
			
		}




		MutantStack& operator=(MutantStack const &rhs_stack)
		{
			if (this != &rhs_stack)
				this->c = rhs_stack.c;
			return *this;
		}


		MutantStack(MutantStack const &stack)
		{
			this->c = stack.c;
		}


		

		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};