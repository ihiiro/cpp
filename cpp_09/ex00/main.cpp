/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/15 01:47:05 by yel-yaqi         ###   ########.fr       */
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



	/*  */
	pair line_pair;
	std::multiset<pair>::iterator lower_bound;
	try
	{
		line_pair = process_line(input_file, RIGHT_FILE);
		lower_bound = ref_multiset.lower_bound(line_pair);
		if ((*lower_bound).DATE != line_pair.DATE)
			std::cout << "[" << line_pair.DATE << "] * " << "[ " << (*--lower_bound).DATE << "] = "
			<< line_pair.VALUE << " * " << (*lower_bound).VALUE << " = " <<
			line_pair.VALUE * (*lower_bound).VALUE << std::endl;
		else
			std::cout << "[" << line_pair.DATE << "] * " << "[ " << (*lower_bound).DATE << "] = "
				<< line_pair.VALUE << " * " << (*lower_bound).VALUE << " = " <<
				line_pair.VALUE * (*lower_bound).VALUE << std::endl;
	}
	catch (char const *e) { std::cout << "error: \n\t" << e << ", next" << std::endl; }
	while (line_pair.DATE != traits_type::eof())
	{
		try
		{
				
		}
		catch (char const *e) { std::cout << "error: \n\t" << e << ", next" << std::endl; }
	}
	
	// std::multiset<pair>::iterator begin = ref_multiset.begin();

	// // for (; begin != ref_multiset.end(); begin++)
	// // 	std::cout << (*begin).DATE << std::endl;

	// std::cout << (*begin).DATE << std::endl;
	// begin++;
	// std::cout << (*begin).DATE << std::endl;

	// std::cout << ref_multiset.size();

	
}
