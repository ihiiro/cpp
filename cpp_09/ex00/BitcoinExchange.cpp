/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:09 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/12 01:37:33 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

/*

process_year( stream , arr )
	1st character is 2 then (add equivalent to yi) else (throw "BAD LINE")
	2nd character is 0 then (add equivalent to yi) else (throw "BAD LINE")
	3rd character in range [0, 2] then (add equivalent to yi) else (throw "BAD LINE")
	4th character in range [0, 9] then (add equivalent to yi) else (throw "BAD LINE")
	set arr[1] to 29 if leap year
	return yi

*/

int process_year(std::ifstream stream, int *feb_ptr)
{
	int yi = 0;
	// will allow "space" for MMDD by keeping a tail of 0s
	int order = 10000000; // 10 ^ 7 is the max order of magnitude in YYYYMMDD
	char c = stream.get();

	(c == '2') ? yi += (c - '0') * order : throw "BAD LINE";
	c = stream.get();
	order /= 10;
	(c == '0') ? yi += (c - '0') * order : throw "BAD LINE";
	c = stream.get();
	order /= 10;
	(c >= '0' and c <= '2') ? yi += (c - '0') * order : throw "BAD LINE";
	c = stream.get();
	order /= 10;
	(c >= '0' and c <= '9') ? yi += (c - '0') * order : throw "BAD LINE";
	/* dividing by 10 ^ 4 gives us the year portion
		if its divisible by 4 then its a leap year
	*/
	if (yi / 10000 % 4 == 0)
		*feb_ptr = 29;
	return yi;
}

/*

process_month( stream )
	1st character in range [0, 1] then (add equivalent to mi) else (throw "BAD LINE") <==== A
	if A is 0 then
		2nd character in range [1, 9] then (add equivalent to mi) else (throw "BAD LINE")
	else A is 1 then
		2nd character in range [0, 2] then (add equivalent to mi) else (throw "BAD LINE")
	return mi

*/