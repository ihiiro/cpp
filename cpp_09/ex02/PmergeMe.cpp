/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:42:28 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/03/01 03:10:45 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <cstdlib>


template< typename T >
T pairwise_reduce ( T& container , int R )
{
	size_t i = 0;
	T reduced;
	ATOM *smaller = new ATOM;
	ATOM larger;
	ATOM *ptr;

	while ( i + 1 < container.size() )
	{
		if ( container [ i ].integer < container [ i + 1 ].integer )
		{
			larger = container [ i + 1 ];
			*smaller = container [ i ];
		}
		else
		{
			larger = container [ i ];
			*smaller = container [ i + 1 ];
		}
		ptr = &larger;
		for ( int j = 0 ; j < R ; j += 2 )
			ptr = ptr->pair_chain;
	}

	return reduced;
}

template < typename T >
void merge_insertion ( T& container , T& S , int R )
{
	if ( container.size() == 1 )
	{
		S.push_back( container[ 0 ] );
		return;
	}

	T container_of_largest_in_pairs = pairwise_reduce ( container , R );
	merge_insertion ( &container_of_largest_in_pairs , S , R + 1 );
	ATOM *a1_pairing = pair_chain_lookup ( S[ 0 ] , R );
	if ( a1_pairing != NULL )
		S.insert ( 0 , *a1_pairing );
	insert ( container , S , R );
}