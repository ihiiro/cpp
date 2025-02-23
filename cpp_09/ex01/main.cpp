/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:08:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/02/23 04:22:57 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>

#include <stack>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "ERROR: ./RPN \"<RPN expression\"" << std::endl;
		return 1;
	}

	if (argv == NULL)
	{
		std::cerr << "ERROR: FATAL: NULL ARGV" << std::endl;
		return 1;
	}

	if (argv[1] == NULL)
	{
		std::cerr << "ERROR: FATAL: NULL *ARGV" << std::endl;
		return 1;
	}

	if (argv[1][0] == '\0')
	{
		std::cerr << "ERROR: empty string" << std::endl;
		return 1;
	}

	/*  */
	std::stack<long> stack;
	long a;
	long b;
	for (size_t i = 0 ; ; i += 2)
	{
		if (argv[1][i + 1] == ' ' or argv[1][i + 1] == '\0')
		{
			if (argv[1][i] >= '0' and argv[1][i] <= '9')
				stack.push(argv[1][i] - '0');
			else if (argv[1][i] == '+' or argv[1][i] == '-'
					or argv[1][i] == '*' or argv[1][i] == '/')
			{
				if (stack.size() >= 2)
				{
					// pop items in order
					b = stack.top();
					stack.pop();
					a = stack.top();
					stack.pop();
					// evaluate a OP b
					switch (argv[1][i])
					{
						case '+': stack.push(a + b);
							break;
						case '-': stack.push(a - b);
							break;
						case '*': stack.push(a * b);
							break;
						case '/': {
							if (b != 0)
								stack.push(a / b);
							else
							{
								std::cerr << "ERROR: division by 0 is undefined '"
								<< argv[1][i] << argv[1][i + 1] << "'" << std::endl;
								return 1;
							}
							};
					}
					// check if it overflows a 32 bit int in either direction
					if (stack.top() > INT32_MAX or stack.top() < INT32_MIN)
					{
						std::cerr << "ERROR: result can't fit in INT" << std::endl;
						return 1;
					}
				}
				else
				{
					// stack size is less than 2 which means we can't do the arithmetic
					std::cerr << "PARSE ERROR: insufficient operands to binary operation '" << argv[1][i]
						<< argv[1][i + 1] << "'" << std::endl;
					return 1;
				}
			}
			else
			{
				std::cerr << "PARSE ERROR: can't recognize token '" << argv[1][i] << argv[1][i + 1]
					<< "'" << std::endl;
				return 1;
			}
			if (argv[1][i + 1] == '\0')
				break;
		}
		else
		{
			std::cerr << "PARSE ERROR: tokens must be separated by a space character '" << argv[1][i]
			<< argv[1][i + 1] << "'" << std::endl;
			return 1;
		}
	}
	if (stack.empty() or stack.size() > 1)
	{
		std::cerr << "ERROR: invalid expression" << std::endl;
		return 1;
	}
	std::cout << "RESULT: " << stack.top() << std::endl;
	return 0;
}
