/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/13 02:49:54 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

#include <cstring>


int main(int argc, char **argv)
{
	if (argc != 2) // program only works with two args
		return usage_error("./btc <filename>.txt"), 1;


	/* NULL protections */
	if (argv == NULL)
		return fatal_error("NULL argv ptr"), 1;
	if (argv[1] == NULL)
		return fatal_error("NULL *argv ptr"), 1;




	char const *filename = argv[1];
	char const *ref_filename = "data.csv";
	if (not std::strcmp(filename, ref_filename))
		return stupidity_error("using reference file as input file makes no sense"), 1;



	/* unopenable/empty file protection */
	std::ifstream input_file(filename); // input file
	if (not input_file)
		return fatal_error("couldn't open input file for reading"), 1;
	if (input_file.get() == traits_type::eof())
		return usage_error("empty input file"), 1;
	std::ifstream ref_file(ref_filename); // reference file
	if (not ref_file)
		return fatal_error("couldn't open reference file for reading"), 1;
	if (ref_file.get() == traits_type::eof())
		return usage_error("empty reference file"), 1;
	input_file.unget();
	ref_file.unget();


	try
	{pair line_pair = process_line(input_file);
	std::cout << line_pair.DATE << std::endl;
	std::cout << line_pair.VALUE << std::endl;}
	catch (int i)
	{
		std::cout << "caught: " << i << std::endl;
	}

	/*    proto   */
	
	// char c = input_file.get();



	// while (c != '\n' and c != traits_type::eof())
	// {
	// 	std::cout << c;

		
		
	// 	c = input_file.get();
	// }





	
	
	
}

/*

process_year( stream , arr )
	1st character is 2 then (add equivalent to yi) else (throw "BAD LINE")
	2nd character is 0 then (add equivalent to yi) else (throw "BAD LINE")
	3rd character in range [0, 2] then (add equivalent to yi) else (throw "BAD LINE")
	4th character in range [0, 9] then (add equivalent to yi) else (throw "BAD LINE")
	set arr[1] to 29 if leap year
	return yi

process_month( stream )
	1st character in range [0, 1] then (add equivalent to mi) else (throw "BAD LINE") <==== A
	if A is 0 then
		2nd character in range [1, 9] then (add equivalent to mi) else (throw "BAD LINE")
	else A is 1 then
		2nd character in range [0, 2] then (add equivalent to mi) else (throw "BAD LINE")
	return mi

process_day( stream , month , arr )
	1st character in range [0, 9] then (add equivalent to di) else (throw "BAD LINE") 
	2nd character in range [0, 9] then (add equivalent to di) else (throw "BAD LINE") 
	mi in range [1, arr[month - 1]]
	arr[1] = 28;

process_value( stream )
	nth character in range [0, 9] --> (n+k)th character is '.' --> (n+k+p)th character in range [0, 9]
	last character is '\n' or eof
	return (string copy of value)

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

for line in stream
	process_line()


*/