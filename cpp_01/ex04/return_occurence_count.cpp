/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_occurence_count.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:01:21 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/15 13:17:40 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "return_occurence_count.hpp"

size_t return_occurence_count(std::string &string, char *substr)
{
	size_t count = 0;
	size_t string_char_size = string.size();
	size_t substr_char_size = std::strlen(substr);
	if (
		string_char_size == 0 or
		substr_char_size == 0 or
		substr_char_size > string_char_size
	)
		return (0);
	for (size_t pos = 0; (pos = string.find(substr, pos)) != std::string::npos; pos++, count++);
	return (count);
}