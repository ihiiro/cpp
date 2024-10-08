/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_aggregate_str.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:57:05 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/15 17:38:54 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "return_aggregate_str.hpp"

std::string* return_aggregate_str(char *filename, std::streamsize *gcount_aggregate, struct statvfs& fsstats)
{
	std::ifstream 	ifstream(filename);
	if (!ifstream.is_open())
		return (NULL);
	char		  	buf[fsstats.f_frsize];
	std::string	  	*full_char_content = new std::string("");
	std::streamsize gcount = 0;

	while (!ifstream.eof())
	{
		ifstream.read(buf, fsstats.f_frsize);
		gcount = ifstream.gcount();
		full_char_content->append(buf, gcount);
		*gcount_aggregate += gcount;
		std::memset(buf, 0, fsstats.f_frsize);
	}
	return (full_char_content);
}