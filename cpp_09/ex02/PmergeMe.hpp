/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:42:25 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/03/01 04:04:38 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>

#include <vector>


typedef struct atom_s
{
	int integer;
	struct atom_s *pair_chain;
}  ATOM;

template < typename T >
void merge_insertion ( T& container , T& S , int R );
