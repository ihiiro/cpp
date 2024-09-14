/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_aggregate_str.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:57:05 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/14 05:10:57 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.hpp"
#include "return_aggregate_str.hpp"

std::string* return_aggregate_str(char *filename, std::streamsize *gcount_aggregate)
{
	std::ifstream 	ifstream(filename);
	if (!ifstream.is_open())
		return (NULL);
	char		  	buf[APFS_BLOCK_SIZE];
	std::string	  	*full_char_content = new std::string[1]; // this needs to be freed later
	std::streamsize gcount = 0;

	while (!ifstream.eof())
	{
		ifstream.read(buf, APFS_BLOCK_SIZE);
		gcount = ifstream.gcount();
		full_char_content->append(buf, gcount);
		*gcount_aggregate += gcount;
		std::memset(buf, 0, APFS_BLOCK_SIZE);
	}
	return (full_char_content);
}