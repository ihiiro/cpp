/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_aggregate_str.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:57:05 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/14 04:32:58 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.hpp"
#include "return_aggregate_str.hpp"

std::string return_aggregate_str(char *filename, std::streamsize *gcount_aggregate)
{
	std::ifstream 	ifstream(filename);
	char		  	buf[APFS_BLOCK_SIZE];
	std::string	  	full_char_content;
	std::streamsize gcount = 0;

	while (!ifstream.eof())
	{
		ifstream.read(buf, APFS_BLOCK_SIZE);
		gcount = ifstream.gcount();
		full_char_content.append(buf, gcount);
		*gcount_aggregate += gcount;
		std::memset(buf, 0, APFS_BLOCK_SIZE);
	}
	return (full_char_content);
}