/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:22:25 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/18 14:56:34 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>

template <typename T, typename U>
void iter(T *addr, U len, void (*f)(T const&))
{
	if (addr == NULL)
		return;
	for (U i = U(0); i < len; i++)
		f(addr[i]);
}