/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:09 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/13 21:53:07 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>


#include "BitcoinExchange.hpp"

/* for floating point comparisons */
bool equal(double a, double b)
{
	return std::abs(a - b) < EPSILON;
}

bool less(double a, double b)
{
	return a < b and !equal(a, b);
}

bool more(double a, double b)
{
	return a > b and !equal(a, b);
}









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
		if it's divisible by 4 then its a leap year
	*/
	if (yi / 10000 % 4 == 0)
		*feb_ptr = 29;
	if (yi < 20090000 or yi > 20250000)
		throw BAD_YEAR;
	return yi;
}








int process_month(std::ifstream& stream)
{
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













int process_day(std::ifstream& stream, int month, int *months)
{
	int di = 0;
	int order = 10; // 10 ^ 1 because DD sits in positions 10 ^ 0 and 10 ^ 1
	char c = stream.get();

	(c >= '0' and c <= '9') ? di += (c - '0') * order : throw BAD_DAY;
	order /= 10;
	c = stream.get();
	(c >= '0' and c <= '9') ? di += (c - '0') * order : throw BAD_DAY;
	if (di >= 1 and di <= months[month - 1])
	{
		months[1] = 28; // return february to begin 28 days
		return di;
	}
	throw BAD_DAY;
}












std::string process_value(std::ifstream& stream)
{
	std::string value_copy;
	char c = stream.get();

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
	if (c == traits_type::eof() or c == '\n')
		return value_copy;
	c = stream.get(); // skip '.'
	if (c < '0' or c > '9')
		throw BAD_VALUE;
	while (c != traits_type::eof() and c != '\n') // fractional part
	{
		if (c < '0' or c > '9')
			throw BAD_VALUE;
		value_copy += c;
		c = stream.get();
	}
	return value_copy;
}














pair process_line(std::ifstream& stream)
{
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	months[0]  = 31;
	int month;
	pair line_pair = {0, 0};
	char const *c_str;

	line_pair.DATE += process_year(stream, &months[1]);
	if (stream.get() != '-')
		throw MISSING_DASH;
	month = process_month(stream);
	line_pair.DATE += month;
	if (stream.get() != '-')
		throw MISSING_DASH;
	/* month/100 so we get the month portion only */
	line_pair.DATE += process_day(stream, month / 100, months);
	if (stream.get() != ' ')
		throw MISSING_SPACE;
	if (stream.get() != '|')
		throw MISSING_PIPE;
	if (stream.get() != ' ')
		throw MISSING_SPACE;
	c_str = process_value(stream).c_str();
	if (c_str == NULL)
	{
		fatal_error("NULL ptr");
		std::exit(1);
	}
	line_pair.VALUE = std::atof(c_str);
	if ( 
		(more(line_pair.VALUE, 0) or equal(line_pair.VALUE, 0)) and 
			(less(line_pair.VALUE, 1000) or equal(line_pair.VALUE, 1000))	) // <==> VALUE >= 0 and VALUE <= 1000
		return line_pair;
	throw BAD_VALUE;
}