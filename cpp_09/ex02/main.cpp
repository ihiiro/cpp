/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:41:11 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/03/01 04:56:24 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
	
	std::vector < ATOM > X;

	X.push_back ( (ATOM){ 1 , NULL } );
	X.push_back ( (ATOM){ 3 , NULL } );
	X.push_back ( (ATOM){ 0 , NULL } );
	X.push_back ( (ATOM){ 4 , NULL } );
	X.push_back ( (ATOM){ 9 , NULL } );

	std::vector < ATOM > S;

	
	merge_insertion < std::vector<ATOM> > ( X , S , 1 );

	// std::cout << S.size() << std::endl;

	argc++ ; (void)argv;

	return 0;
	
}

#include "PmergeMe.tpp"
