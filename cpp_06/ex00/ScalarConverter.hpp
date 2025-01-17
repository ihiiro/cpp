/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:51:11 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/17 11:29:03 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &obj);
		ScalarConverter &operator=(ScalarConverter const &obj);
	public:
		static void convert(std::string literal);
		~ScalarConverter();
};