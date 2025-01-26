/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:23:12 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/26 19:23:40 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

#include <fstream>

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
	std::ifstream ifstream_input_file(filename); // input file
	if (not ifstream_input_file)
		return fatal_error("couldn't open input file for reading"), 1;
	if (ifstream_input_file.get() == std::ifstream::traits_type::eof())
		return usage_error("empty input file"), 1;
	std::ifstream ifstream_ref_file(ref_filename); // reference file
	if (not ifstream_ref_file)
		return fatal_error("couldn't open reference file for reading"), 1;
	if (ifstream_ref_file.get() == std::ifstream::traits_type::eof())
		return usage_error("empty reference file"), 1;




	
	
	
	
}