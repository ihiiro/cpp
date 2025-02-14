/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/14 22:24:25 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

#include <cstring>

#include <set>


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

	// try
	// {pair line_pair = process_line(input_file, RIGHT_FILE);
	// std::cout << line_pair.DATE << std::endl;
	// std::cout << line_pair.VALUE << std::endl;}
	// catch (char const *s)
	// {
	// 	std::cout << "caught: " << s << std::endl;
	// }

	std::multiset<pair> ref_multiset;

	try
	{
		for (pair line_pair = process_line(ref_file, LEFT_FILE); 
			line_pair.DATE != traits_type::eof(); 
			line_pair = process_line(ref_file, LEFT_FILE))
			ref_multiset.insert(line_pair);
	}
	catch (char const *s)
	{
		std::cout << s << std::endl;
	}
	

	
	std::multiset<pair>::iterator begin = ref_multiset.begin();

	// for (; begin != ref_multiset.end(); begin++)
	// 	std::cout << (*begin).DATE << std::endl;

	std::cout << (*begin).DATE << std::endl;
	begin++;
	std::cout << (*begin).DATE << std::endl;

	std::cout << ref_multiset.size();

	
}
