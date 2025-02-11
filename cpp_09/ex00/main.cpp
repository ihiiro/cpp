/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/11 22:52:07 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

#include <fstream>

#include <cstring>

typedef std::ifstream::traits_type traits_type;

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



	/*    proto   */
	
	char c = input_file.get();



	while (c != '\n' and c != traits_type::eof())
	{
		std::cout << c;

		
		
		c = input_file.get();
	}





	
	
	
}

/*

process_year( stream )
	1st character is 2 then (add equivalent to yi) else (throw "BAD LINE")
	2nd character is 0 then (add equivalent to yi) else (throw "BAD LINE")
	3rd character in range [0, 2] then (add equivalent to yi) else (throw "BAD LINE")
	4th character in range [0, 9] then (add equivalent to yi) else (throw "BAD LINE")
	return yi

process_md( stream )
	1st character in range [0, 1] then (add equivalent to yi) else (throw "BAD LINE")

*/