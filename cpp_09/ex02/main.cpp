/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:41:11 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/03/02 17:52:13 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
	
	std::vector < ATOM > X;

	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );
	X.push_back ( (ATOM){ 1 , NULL } );
	X.push_back ( (ATOM){ 3 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 4 , NULL } );
	X.push_back ( (ATOM){ 5 , NULL } );
	X.push_back ( (ATOM){ 7 , NULL } );
	X.push_back ( (ATOM){ 7 , NULL } );
	X.push_back ( (ATOM){ 7 , NULL } );
	X.push_back ( (ATOM){ 7 , NULL } );
	X.push_back ( (ATOM){ 7 , NULL } );
	X.push_back ( (ATOM){ 2 , NULL } );

	// [1, 3, 0, 4, 9]
	// [3, 4]
	// [4]

	std::vector < ATOM > S;

	
	merge_insertion < std::vector<ATOM> > ( X , S , 0 );

	// std::cout << S.size() << std::endl;

	for ( size_t i = 0 ; i < S.size() ; i++ )
		std::cout << S [ i ].integer << std::endl;

	argc++ ; (void)argv;

	return 0;
	
}

#include "PmergeMe.tpp"
