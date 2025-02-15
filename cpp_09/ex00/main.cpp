/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/15 03:54:41 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

#include <cstring>

#include <set>


int main(int argc, char **argv)
{
	if (argc != 2) // program only works with two args
		return usage_error("./btc filename"), 1;


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




	
	/* fill the multiset with the reference file data */
	std::multiset<pair> ref_multiset;
	try
	{
		for (pair line_pair = process_line(ref_file, LEFT_FILE); 
				  line_pair.DATE != traits_type::eof(); 
				  line_pair = process_line(ref_file, LEFT_FILE))
			ref_multiset.insert(line_pair);
	}
	catch (char const*) {}



	/* compute for each line in RIGHT_FILE using the value in LEFT_FILE */
	pair line_pair;
	while ( 1 )
	{
		try
		{
			line_pair = process_line(input_file, RIGHT_FILE);
			if (line_pair.DATE == traits_type::eof())
				break;
			compute(ref_multiset, line_pair);
		}
		catch (char const *e) 
		{
			std::cout << "error: " << e << ", next" << std::endl;
		}
	}
}
