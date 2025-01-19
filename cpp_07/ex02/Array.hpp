/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:29:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/19 20:05:16 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <cstdlib>
#include <exception>
#include <iostream>

template <typename T>
class Array
{
	T *array;
	size_t len;
	public: 


		T& operator[](size_t index)
		{
			if (array == NULL)
			{
				std::cout << "unrecoverable error: subscript on NULL array"
					<< std::endl;
				std::exit(1);
			}
			if (index > len - 1 or index < 0)
				throw std::exception();
			else
				return array[index];
		}

	
		Array()
		{
			array = NULL;
			len = 0;
		}



		
		Array(unsigned int n)
		{
			try
			{
				array = new T[n]; // default-initialized
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
				std::exit(1);
			}
			len = n;
		}




		
		Array(Array const &src)
		{
			try
			{
				array = new T[src.size()];
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
				std::exit(1);
			}
			for (size_t i(0); i < src.size(); i++)
				array[i] = src.array[i];
			len = src.size();
		}




		
		Array& operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				delete [] array;
				try
				{
					array = new T[rhs.size()];
				}
				catch (std::exception& e)
				{
					std::cout << e.what() << std::endl;
					std::exit(1);
				}
				for (size_t i(0); i < rhs.size(); i++)
					array[i] = rhs.array[i];
				len = rhs.size();
			}
			return *this;
		}



		
		~Array()
		{
			delete [] array;
		}


		size_t size() const
		{
			return len;
		}
};