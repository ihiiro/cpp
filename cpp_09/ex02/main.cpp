/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:41:11 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/03/05 15:32:19 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <vector>
#include <iostream>

#include <deque>

int main(int argc, char **argv)
{
	std::deque < ATOM > X;

	X.push_back ( (ATOM){ 0 , 0 , NULL } );
	X.push_back ( (ATOM){ 3 , 0 , NULL } );
	X.push_back ( (ATOM){ 2 , 0 , NULL } );
	X.push_back ( (ATOM){ 1 , 0 , NULL } );
	X.push_back ( (ATOM){ 4 , 0 , NULL } );
	X.push_back ( (ATOM){ 5 , 0 , NULL } );
	X.push_back ( (ATOM){ 6 , 0 , NULL } );
	X.push_back ( (ATOM){ 33 , 0 , NULL } );
	X.push_back ( (ATOM){ 52 , 0 , NULL } );
	X.push_back ( (ATOM){ 7 , 0 , NULL } );
	X.push_back ( (ATOM){ 6 , 0 , NULL } );
	X.push_back ( (ATOM){ 9 , 0 , NULL } );
	X.push_back ( (ATOM){ 5 , 0 , NULL } );
	X.push_back ( (ATOM){ 1234 , 0 , NULL } );
	X.push_back ( (ATOM){ -1234 , 0 , NULL } );
	X.push_back ( (ATOM){ 12 , 0 , NULL } );
	X.push_back ( (ATOM){ 18 , 0 , NULL } );
	X.push_back ( (ATOM){ 22 , 0 , NULL } );
	X.push_back ( (ATOM){ 34 , 0 , NULL } );
	X.push_back ( (ATOM){ 43 , 0 , NULL } );
	X.push_back ( (ATOM){ 55 , 0 , NULL } );
	X.push_back ( (ATOM){ 97 , 0 , NULL } );
	X.push_back ( (ATOM){ 28 , 0 , NULL } );
	X.push_back ( (ATOM){ 4 , 0 , NULL } );
	X.push_back ( (ATOM){ 4 , 0 , NULL } );
	X.push_back ( (ATOM){ 4 , 0 , NULL } );

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
