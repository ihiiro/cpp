/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:09 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/18 06:13:15 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>


#include "BitcoinExchange.hpp"



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



/*

	the code below tries to comply with ISO 8601's complete representation
	YYYYMMDD, (2009 january 1st <==> 20090101)
	the date is built by multiplying each digit from left to right by
	a factor of 10^n, n starts at 7 and decreases for each digit.

*/



int process_year(std::ifstream& stream, int *feb_ptr)
{
	int yi = 0;

	for (int order = 1e7; order != 1e3; order /= 1e1)
	{
		char c = stream.peek();
		(c >= '0' and c <= '9') ? yi += (c - '0') * order : throw BAD_YEAR;
		stream.get();
	}
	if (yi < static_cast<int>(2009e4))
		throw BAD_YEAR;
	/* dividing by 10 ^ 4 gives us the year portion
			if it's divisible by 4 then its a leap year
		*/
	if (yi / static_cast<int>(1e4) % 4 == 0)
		*feb_ptr = 29;	
	return yi;
}





int process_month(std::ifstream& stream)
{
	int mi = 0;
	int order = 1000;
	char c = stream.peek();
	char peek_back_c = c;

	(c == '0' or c == '1') ? mi += (c - '0') * order : throw BAD_MONTH;
	order /= 10;
	stream.get();
	c = stream.peek();
	if (peek_back_c == '0')
		(c >= '1' and c <= '9') ? mi += (c - '0') * order : throw BAD_MONTH;
	else if (peek_back_c == '1')
		(c >= '0' and c <= '2') ? mi += (c - '0') * order : throw BAD_MONTH;
	stream.get();
	return mi;
}













int process_day(std::ifstream& stream, int month, int *months)
{
	int di = 0;
	int order = 10;
	char c = stream.peek();

	(c >= '0' and c <= '9') ? di += (c - '0') * order : throw BAD_DAY;
	order /= 10;
	stream.get();
	c = stream.peek();
	(c >= '0' and c <= '9') ? di += (c - '0') * order : throw BAD_DAY;
	stream.get();
	if (di >= 1 and di <= months[month - 1])
		return di;
	throw BAD_DAY;
}










std::string process_value(std::ifstream& stream)
{
	std::string value_copy;
	char c = stream.peek();

	if (c < '0' or c > '9')
		throw BAD_VALUE;
	while ( 1 ) // integer part
	{
		value_copy += c;
		if (c == '.')
			break;
		if (c == '\n' or c == traits_type::eof())
			return value_copy;
		if (c < '0' or c > '9')
			throw BAD_VALUE;
		stream.get();
		c = stream.peek();
	}
	stream.get(); // extract '.'
	if ((c = stream.peek()) < '0' or c > '9')
		throw BAD_VALUE;
	while ( 1 ) // fractional part
	{
		if (c == '\n' or c == traits_type::eof())
			break;
		if (c < '0' or c > '9')
			throw BAD_VALUE;
		value_copy += c;
		stream.get();
		c = stream.peek();
	}
	return value_copy;
}














pair process_line(std::ifstream& stream, double FILE_TYPE)
{
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	months[0]  = 31;
	int month;
	pair line_pair(0, 0);
	char const *c_str;


	for (char c; ;) // skip line
	{
		if ((c = stream.get()) == '\n')
			break;
		if (c == traits_type::eof())
			return pair(traits_type::eof(), 0);
	}





	
	line_pair.DATE += process_year(stream, &months[1]);
	(stream.peek() != '-') ? throw MISSING_DASH : stream.get();
	month = process_month(stream);
	line_pair.DATE += month;
	(stream.peek() != '-') ? throw MISSING_DASH : stream.get();
	/* month/100 so we get the month portion only */
	line_pair.DATE += process_day(stream, month / 100, months);
	if (FILE_TYPE == RIGHT_FILE)
	{
		(stream.peek() != ' ') ? throw MISSING_SPACE : stream.get();
		(stream.peek() != '|') ? throw MISSING_PIPE : stream.get();
		(stream.peek() != ' ') ? throw MISSING_SPACE_AFTER_PIPE : stream.get();
	}
	else
		(stream.peek() != ',') ? throw MISSING_COMMA : stream.get();




			
	c_str = process_value(stream).c_str();
	if (c_str == NULL)
	{
		fatal_error("NULL ptr");
		std::exit(1);
	}
	line_pair.VALUE = std::atof(c_str);
	if (line_pair.DATE < 20090102)
		throw BAD_DATE;
	if ( 
		(more(line_pair.VALUE, 0) or equal(line_pair.VALUE, 0)) and 
			(less(line_pair.VALUE, FILE_TYPE) or equal(line_pair.VALUE, FILE_TYPE))	) // <==> VALUE >= v and VALUE <= v
		return line_pair;
	throw BAD_VALUE;
}






#include <set>
#include <iostream>


/* 

	std::multiset is usually implemented as a self-balancing binary search tree
	therefore lookup takes logarithmic time (the standard guarantees it regardless
	of the actual implementation)

 */

void compute(std::multiset<pair>& ref_multiset, pair line_pair)
{
	std::multiset<pair>::iterator lower_bound = ref_multiset.lower_bound(line_pair);

	if ((*lower_bound).DATE != line_pair.DATE)
		std::cout << "[" << line_pair.DATE << "] * " << "[ " << (*--lower_bound).DATE << "] = "
		<< line_pair.VALUE << " * " << (*lower_bound).VALUE << " = " <<
		line_pair.VALUE * (*lower_bound).VALUE << std::endl;
	else
		std::cout << "[" << line_pair.DATE << "] * " << "[ " << (*lower_bound).DATE << "] = "
			<< line_pair.VALUE << " * " << (*lower_bound).VALUE << " = " <<
			line_pair.VALUE * (*lower_bound).VALUE << std::endl;		
}