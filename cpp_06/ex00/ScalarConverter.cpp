/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:51:13 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/17 12:08:20 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const&){}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const&){ return *this; }
ScalarConverter::~ScalarConverter(){}




/* check if two double precision values are roughly equal */
double xabs(double x)
{
	if (x < 0)
		return -x;
	return x;
}
double equal(double a, double b)
{
	return xabs(a - b) < .0001;
}







/* print literal as: char, int, double, float to stdout */
void print_conversions(double literal, std::string original)
{
	// char
	if (std::atof(original.data()) > CHAR_MAX
		or std::atof(original.data()) < 0
		or original == "-inf" or original == "-inff"
		or original == "+inf" or original == "+inff"
		or original == "nanf" or original == "nan")
		std::cout << "char: impossible" << std::endl;
	else if (static_cast<char>(literal) >= 0 and static_cast<char>(literal) <= 31)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" <<
		static_cast<char>(literal) << "'" << std::endl;
	// int
	if (std::atof(original.data()) > INT_MAX or std::atof(original.data()) < INT_MIN 
		or original == "-inf" or original == "-inff"
		or original == "+inf" or original == "+inff"
		or original == "nanf" or original == "nan")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " <<
		static_cast<int>(literal) << std::endl;
	// float
	std::cout << "float: " <<
	static_cast<float>(literal);
	if (equal(literal - static_cast<int>(literal), 0))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	// double
	std::cout << "double: " << literal;
	if (equal(literal - static_cast<int>(literal), 0))
		std::cout << ".0";
	std::cout << std::endl;
}










/* detect and convert literals to detected type */
void ScalarConverter::convert(std::string literal)
{
	float f; double d; int i; char c; // types
	size_t first_not_digit = literal.find_first_not_of("-+.0123456789", 0);
	size_t size = literal.size();
	// char
	if ((literal[0] < '0' or literal[0] > '9')
		and size == 1)
	{
		c = static_cast<char>(literal[0]);
		print_conversions(static_cast<double>(c), literal);
	}
	// float
	else if (literal == "+inff" or literal == "-inff" or 
			literal == "nanf" or
				(first_not_digit == size - 1 and
				literal[first_not_digit] == 'f'))
	{
		f = static_cast<float>(std::atof(literal.data()));
		print_conversions(static_cast<double>(f), literal);
	}
	// double
	else if (literal.find('.') != std::string::npos
		or literal == "-inf" or literal == "+inf"
		or literal == "nan")
	{
		d = std::atof(literal.data());
		print_conversions(d, literal);
	}
	// int
	else
	{
		i = static_cast<int>(std::atof(literal.data()));
		print_conversions(static_cast<double>(i), literal);
	}
}