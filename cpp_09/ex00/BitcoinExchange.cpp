/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:09 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/13 02:53:59 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <cstring>


#include "BitcoinExchange.hpp"

/*

process_year( stream , arr )
	1st character is 2 then (add equivalent to yi) else (throw "BAD LINE")
	2nd character is 0 then (add equivalent to yi) else (throw "BAD LINE")
	3rd character in range [0, 2] then (add equivalent to yi) else (throw "BAD LINE")
	4th character in range [0, 9] then (add equivalent to yi) else (throw "BAD LINE")
	set arr[1] to 29 if leap year
	return yi

*/

int process_year(std::ifstream& stream, int *feb_ptr)
{
	int yi = 0;
	// will allow "space" for MMDD by keeping a tail of 0s
	int order = 10000000; // 10 ^ 7 is the max order of magnitude in YYYYMMDD
	char c = stream.get();

	(c == '2') ? yi += (c - '0') * order : throw BAD_YEAR;
	c = stream.get();
	order /= 10;
	(c == '0') ? yi += (c - '0') * order : throw BAD_YEAR;
	c = stream.get();
	order /= 10;
	(c >= '0' and c <= '2') ? yi += (c - '0') * order : throw BAD_YEAR;
	c = stream.get();
	order /= 10;
	(c >= '0' and c <= '9') ? yi += (c - '0') * order : throw BAD_YEAR;
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

int process_month(std::ifstream& stream)
{
	// possibly gonna need to catch "BAD LINE" here (propagate?)
	int mi = 0;
	int order = 1000; // 10 ^ 3 because we want the month portion to set where it should
	char c = stream.get();
	char peek_back_c = c; // only need one peek backwards (only two digits: MM)

	(c >= '0' and c <= '1') ? mi += (c - '0') * order : throw BAD_MONTH;
	order /= 10;
	c = stream.get();
	if (peek_back_c == '0')
		(c >= '1' and c <= '9') ? mi += (c - '0') * order : throw BAD_MONTH;
	else if (peek_back_c == '1')
		(c >= '0' and c <= '2') ? mi += (c - '0') * order : throw BAD_MONTH;
	else
		throw BAD_MONTH;
	return mi;
}

/*

process_day( stream , month , arr )
	1st character in range [0, 9] then (add equivalent to di) else (throw "BAD LINE") 
	2nd character in range [0, 9] then (add equivalent to di) else (throw "BAD LINE") 
	di in range [1, arr[month - 1]]
	arr[1] = 28;

*/

int process_day(std::ifstream& stream, int month, int *months)
{
	// possibly gonna need to catch "BAD LINE" here (propagate?)
	int di = 0;
	int order = 10; // 10 ^ 1 because DD sits in positions 10 ^ 0 and 10 ^ 1
	char c = stream.get();

	(c >= '1' and c <= '9') ? di += (c - '0') * order : throw "first";
	order /= 10;
	c = stream.get();
	(c >= '1' and c <= '9') ? di += (c - '0') * order : throw "second";
	if (di >= 1 and di <= months[month - 1])
	{
		months[1] = 28; // return february to begin 28 days
		return di;
	}
	months[1] = 28;
	throw months[month-1];
}

/*

process_value( stream )
	nth character in range [0, 9] --> (n+k)th character is '.' --> (n+k+p)th character in range [0, 9]
	last character is '\n' or eof
	return (string copy of value)

*/

char *process_value(std::ifstream& stream)
{
	std::string value_copy;
	char *value;
	char c = stream.get();
	size_t size;

	if (c < '0' or c > '9')
		throw BAD_VALUE;
	while (c != traits_type::eof() and c != '\n') // integer part
	{
		value_copy += c;
		if (c == '.')
			break;
		if (c < '0' or c > '9')
			throw BAD_VALUE;
		c = stream.get();
	}
	size = value_copy.size() + 1;
	value = new char[size];
	std::strncpy(value, value_copy.c_str(), size);
	if (c == traits_type::eof() or c == '\n')
		return value;
	delete value;
	c = stream.get(); // skip '.'
	while (c != traits_type::eof() and c != '\n') // fractional part
	{
		if (c < '0' or c > '9')
			throw BAD_VALUE;
		value_copy += c;
		c = stream.get();
	}
	size = value_copy.size() + 1;
	value = new char[size];
	std::strncpy(value, value_copy.c_str(), size);
	return value;
}

/*

process_line()
	process_year() <=== A
	character after A is '-' else (throw "BAD LINE")
	processs_month() <=== B
	character after B is '-' else (throw "BAD LINE")
	process_day() <=== C
	character after C is ' ' else (throw "BAD LINE")
	character after ' ' is '|' else (throw "BAD LINE")
	character after '|' is ' ' else (throw "BAD LINE")
	process_value() <=== D

	DATE <-- A + B + C
	VALUE <-- D (D in range [0, 1000] check in conversion time)
	
	return DATE,VALUE

*/


pair process_line(std::ifstream& stream)
{
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	months[0]  = 31;
	int month;
	pair line_pair = {0, NULL};

	line_pair.DATE += process_year(stream, &months[1]);
	if (stream.get() != '-')
		throw MISSING_DASH;
	month = process_month(stream);
	line_pair.DATE += month;
	if (stream.get() != '-')
		throw MISSING_DASH;
	line_pair.DATE += process_day(stream, month, months);
	if (stream.get() != ' ')
		throw MISSING_SPACE;
	if (stream.get() != '|')
		throw MISSING_PIPE;
	if (stream.get() != ' ')
		throw MISSING_SPACE;
	line_pair.VALUE = process_value(stream);
	return line_pair;
}