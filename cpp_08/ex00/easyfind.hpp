/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:56:05 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/22 16:39:26 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>

template <typename T>
int easyfind(T container, int query)
{
	int i = *std::find(container.begin(), container.end(), query);

	if (query not_eq i)
		throw "easyfind(): can't find query";
	return i;
}