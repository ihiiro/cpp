/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:41:11 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/03/05 17:14:58 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>

#include <vector>

#include <deque>

/*

	N <- 1,000,000
	DEPTH <- ~21
	RAM <- 12mb
	ATOM <- 24B

*/

int main(int argc, char **argv)
{

	std::vector < ATOM > X_vector, S_vector;
	std::deque < ATOM > X_deque, S_deque;

	if ( argc < 3 )
	{

		std::cerr << "ERROR: usage ./PmergeMe A B ..." << std::endl;
		return 1;
 
	}

	if (argv == NULL)
	{
		
		std::cerr << "ERROR: FATAL: NULL ARGV" << std::endl;
		return 1;
		
	}

	

	
	// merge_insertion < std::vector<ATOM> > ( X_vector , S_ , 1 );

	return 0;
	
}

#include "PmergeMe.tpp"
