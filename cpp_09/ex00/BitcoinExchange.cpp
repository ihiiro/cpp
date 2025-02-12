/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:09 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/12 02:14:33 by yel-yaqi         ###   ########.fr       */
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

int process_month(std::ifstream stream)
{
	// possibly gonna need to catch "BAD LINE" here (propagate?)
	char mi = 0;
	int order = 1000; // 10 ^ 3 because we want the month portion to set where it should
	char c = stream.get();
	char peek_back_c = c; // only need one peek backwards (only two digits: MM)

	(c >= '0' and c <= '1') ? mi += (c - '0') * order : throw "BAD LINE";
	order /= 10;
	c = stream.get();
	if (peek_back_c == '0')
		(c >= '1' and c <= '9') ? mi += (c - '0') * order : throw "BAD LINE";
	else if (peek_back_c == '1')
		(c >= '0' and c <= '2') ? mi += (c - '0') * order : throw "BAD LINE";
	else
		throw "BAD LINE";
	return mi;
}

/*

process_day( stream , month , arr )
	1st character in range [0, 9] then (add equivalent to di) else (throw "BAD LINE") 
	2nd character in range [0, 9] then (add equivalent to di) else (throw "BAD LINE") 
	di in range [1, arr[month - 1]]
	arr[1] = 28;

*/

int process_day(std::ifstream stream, int month, int *months)
{
	// possibly gonna need to catch "BAD LINE" here (propagate?)
	char di = 0;
	int order = 10; // 10 ^ 1 because DD sits in positions 10 ^ 0 and 10 ^ 1
	char c = stream.get();

	(c >= '1' and c <= '9') ? di += (c - '0') * order : throw "BAD LINE";
	order /= 10;
	c = stream.get();
	(c >= '1' and c <= '9') ? di += (c - '0') * order : throw "BAD LINE";
	return (di >= 1 and di <= months[month - 1]) ? di : throw "BAD LINE";
}