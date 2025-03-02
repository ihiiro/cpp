/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:42:28 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/03/02 14:59:05 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include <iostream>





#include "PmergeMe.hpp"

#include <cmath>
#include <cstdlib>

#include <vector>

size_t compute_b ( int k )
{

	return ( std::pow ( 2 ,  k + 1 ) + std::pow ( -1 , k ) ) / 3;
	
}

template < typename T >
void binsert ( ATOM target , T& S , long L , long R , long end )
{

	std::cout << "(binsert) target is " << target.integer << std::endl;
	for ( size_t i = 0; i < S.size() ; i++ )
		std::cout << "\tS[i] <-- " << S[i].integer << std::endl;


	size_t m = ( L + R ) / 2;

	if ( L > end )
	{
		S.push_back ( target );
		return;
	}

	if ( L > R )
	{
		S.insert ( S.begin() + L , target );
		return;
	}

	if ( S [ m ].integer < target.integer )
		binsert ( target , S , m + 1 , R , end );
	else
		binsert ( target , S , L , m - 1 , end );

}








template < typename T >
void INSERT ( ATOM target , T& S )
{

	size_t end = S.size() - 1;
	binsert ( target , S , 0 , end , end );

	
}








 
ATOM* pair_chain_lookup ( ATOM atom , int R )
{
	
	ATOM* ptr = &atom;
	for ( int i = 0 ; i < R ; i++ )
		ptr = ptr->pair_chain;

	return ptr;
	
} 








template < typename T >
void insert ( T& container , T& S , int R )
{
	// std::cout << "ffffff" << std::endl;

	T main_chain = S;
	int k = 2;
	size_t prev_group_end = 1;
	bool odd_container = container.size() % 2;
	ATOM container_last = container [ container.size() - 1 ];
	ATOM* pairing;
	size_t b;
	size_t b_copy;



	while ( 1 )
	{
		
		b = compute_b ( k );
		b_copy = b;

		// std::cout << "\tb <-- " << b << " on DEPTH " << R << std::endl;
		if ( b > main_chain.size() - 1 )
		{
			b = main_chain.size() - 1;
			if ( odd_container )
				INSERT ( container_last , S );
			pairing = pair_chain_lookup ( main_chain [ b ] , R );
			while ( b > prev_group_end )
			{
				// std::cout << "\tb <-- " << b << 
				// " ; pairing is " << pairing->integer << std::endl;
				
				INSERT ( *pairing , S );
				b--;
			}
			return;
		}

		pairing = pair_chain_lookup ( main_chain[ b ] , R );
		while ( b > prev_group_end )
		{
			std::cout << "chain owner is " << main_chain [ b ].integer << std::endl;
			INSERT ( *pairing , S );
			b--;
		}

		prev_group_end = b_copy;
		k++;
		
	}
	
}







template < typename T >
T pairwise_reduce ( T& container , int R )
{
	
	std::cout << "\tpairwise_reduce()" << std::endl;


	T reduced;
	// ATOM *smaller = new ATOM;
	ATOM *smaller;
	ATOM larger;
	ATOM *ptr;
	
	for ( size_t i = 0 ; i + 1 < container.size() ; i += 2 )
	{
		
		if ( container [ i ].integer < container [ i + 1 ].integer )
		{
			larger = container [ i + 1 ];
			smaller = &container [ i ];
		}
		else
		{
			larger = container [ i ];
			smaller = &container [ i + 1 ];
		}
		// std::cout << "\tLARGER: " << larger.integer << std::endl;
		// std::cout << "\tSMALLER: " << smaller.integer << std::endl;
		ptr = &larger;
		for ( int j = 0 ; j < R - 1 ; j++ )
			ptr = ptr->pair_chain;
		// std::cout << "\tcontainer size: " << container.size() << std::endl;
		ptr->pair_chain = smaller;

		// std::cout << "larger: " << larger.integer << std::endl;
		// std::cout << "smaller: " << smaller.integer << " " << smaller.pair_chain << std::endl;
		// if (smaller.pair_chain)
		// {
		// 	std::cout << "smaller's pair: " << smaller.pair_chain->integer << std::endl;
		// 	std::cout << "smaller's pair: " << smaller.pair_chain << std::endl;
		// 	std::cout << "smaller's pair's pair: " << smaller.pair_chain->pair_chain << std::endl;
		// 	std::cout << "smaller's pair's pair: " << smaller.pair_chain->pair_chain->pair_chain << std::endl;
			
		// }


		

		// smallerpair_chain  = NULL;
		std::cout << "\t";
		for ( ptr = &larger ; ptr ; ptr = ptr->pair_chain )
			std::cout << ptr->integer << "-->";
		std::cout << std::endl;

		
		reduced.push_back ( larger );
		
	}

	return reduced;
	
}









template < typename T >
void merge_insertion ( T& container , T& S , int R )
{
	std::cout << "RECURSION DEPTH: " << R << std::endl;
	if ( container.size() == 1 )
	{
		std::cout << "\tREACHED BASE" << std::endl;
		S.push_back( container[ 0 ] );
		for ( size_t i = 0; i < S.size() ; i++ )
		{
			std::cout << "DEPTH " << R << "\tS <-- [" << i << "]: " << S[i].integer << std::endl;
			std::cout << "\tpair_chain\n\t"; 
			for (ATOM* ptr = &S [ i ] ; ptr ; ptr = ptr->pair_chain )
				std::cout << ptr->integer << "-->";
			std::cout << std::endl;
		}
		return;
		
	}

	T container_of_largest_in_pairs = pairwise_reduce ( container , R );
	merge_insertion ( container_of_largest_in_pairs , S , R + 1 );


	// std::vector < ATOM > ::iterator it = S.begin();


	


	

	ATOM *a1_pairing = pair_chain_lookup ( S[ 0 ] , R );

	if ( a1_pairing != NULL )
		S.insert ( S.begin() , *a1_pairing );

	for ( size_t i = 0; i < S.size() ; i++ )
	{
		std::cout << "DEPTH " << R << "\tS <-- [" << i << "]: " << S[i].integer << std::endl;
		std::cout << "\tpair_chain\n\t"; 
		for (ATOM* ptr = &S [ i ] ; ptr ; ptr = ptr->pair_chain )
			std::cout << ptr->integer << "-->";
		std::cout << std::endl;
	}

	
	insert ( container , S , R );
	std::cout << "DEPTH " << R << " fine" << std::endl;



}