/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:41:11 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/03/03 15:28:32 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <vector>
#include <iostream>

#include <deque>

int main(int argc, char **argv)
{
	std::deque < ATOM > X;

	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ -9 , NULL } );
	X.push_back ( (ATOM){ -9 , NULL } );
	X.push_back ( (ATOM){ -9 , NULL } );
	X.push_back ( (ATOM){ 2 , NULL } );
	X.push_back ( (ATOM){ 77 , NULL } );
	X.push_back ( (ATOM){ 8 , NULL } );
	X.push_back ( (ATOM){ 33 , NULL } );
	X.push_back ( (ATOM){ 52 , NULL } );
	X.push_back ( (ATOM){ 7 , NULL } );
	X.push_back ( (ATOM){ 6 , NULL } );
	X.push_back ( (ATOM){ 5 , NULL } );
	X.push_back ( (ATOM){ 1234 , NULL } );
	X.push_back ( (ATOM){ -1234 , NULL } );
	X.push_back ( (ATOM){ 12 , NULL } );
	X.push_back ( (ATOM){ 18 , NULL } );
	X.push_back ( (ATOM){ 22 , NULL } );
	X.push_back ( (ATOM){ 34 , NULL } );
	X.push_back ( (ATOM){ 43 , NULL } );
	X.push_back ( (ATOM){ 55 , NULL } );
	X.push_back ( (ATOM){ 97 , NULL } );
	X.push_back ( (ATOM){ 28 , NULL } );
	X.push_back ( (ATOM){ 4 , NULL } );
	X.push_back ( (ATOM){ 4 , NULL } );
	X.push_back ( (ATOM){ 4 , NULL } );

	std::deque < ATOM > S;

	
	merge_insertion < std::deque<ATOM> > ( X , S , 1 );

	// std::cout << S [ 4 ].pair_chain << "\n" << std::endl;
	// std::cout << &S [ 2 ] << "\n" << std::endl;


	for ( size_t i = 0 ; i < S.size() ; i++ )
		std::cout << S [ i ].integer << std::endl;

	argc++ ; (void)argv;

	return 0;
	
}

#include "PmergeMe.tpp"
