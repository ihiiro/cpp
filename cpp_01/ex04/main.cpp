/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:04:14 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/12 07:00:13 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

replace( buf , sorg , srep )
	LOOP buf:
		if (buf[n] == sorg[0])
			if (matches(buf, sorg, n))
				replace_with(sorg, srep, n)

*/

#include <iostream>

#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	(void)argc; // silence for now
	std::string org_file(argv[1]);
	std::string sorg(argv[2]);
	std::string srep(argv[3]);
	std::string rep_file = org_file + ".replace";
	char buf[1024];

	std::ifstream ifstream(org_file); // input stream

	if (!ifstream.is_open())
		return (1);
	
	std::ofstream ofstream(rep_file.c_str()); // output stream

	while (!ifstream.eof())
	{
		ifstream.read(buf, 1024);
		ofstream << buf;
		for (int i = 0; i < 1024; i++)
			buf[i] = 0;
		std::cout << "f";
	}
}
