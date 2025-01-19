/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:29:24 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/19 19:49:40 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

typedef struct arr
{
	int x;
	double y;
}		ARR;

int main()
{
	// empty array
	Array<double> empty;
	// empty[0] = 12.3; // fatal error
	std::cout << "empty size: " << empty.size() 
	<< std::endl;

	// specific size array
	Array<int> int_array(3);
	

	try // from the left
	{
		int_array[-1] = 2;
	}
	catch (std::exception&)
	{
		std::cout << "error: out of bounds (left)" << std::endl;
	}

	try // from the right
	{
		int_array[3] = 2;
	}
	catch (std::exception&)
	{
		std::cout << "error: out of bounds (right)" << std::endl;
	}

	
	int_array[0] = 1;
	int_array[1] = 2;
	int_array[2] = 3;
	std::cout << "======================" << std::endl;
	for (size_t i(0); i < 3; i++) // print array elements and size
		std::cout << int_array[i] << std::endl;
	std::cout << "size: " << int_array.size() << std::endl;
	std::cout << "======================" << std::endl;
	// complex type array
	Array<ARR> ARR_array(2);
	ARR_array[0].x = 1;
	ARR_array[1].y = 1.23;
	for (size_t i(0); i < 2; i++)
		std::cout << ARR_array[i].x << ", " << 
		ARR_array[i].y << std::endl;
	std::cout << "======================" << std::endl;
	// using copy constructor
	Array<ARR> ARR_array1(ARR_array);

	for(size_t i(0); i < 2; i++)
	{
		std::cout << ARR_array1[i].x << "=="
		<< ARR_array[i].x << std::endl;
		
		std::cout << ARR_array1[i].y << "=="
		<< ARR_array[i].y << std::endl;

		std::cout << &ARR_array1[i] << "!="
		<< &ARR_array[i] << std::endl;
	}
	std::cout << "======================" << std::endl;
	Array<ARR> ARR_array2;
	// the assignment overload
	ARR_array2 = ARR_array1;
	for(size_t i(0); i < 2; i++)
	{
		std::cout << ARR_array2[i].x << "=="
		<< ARR_array1[i].x << std::endl;

		std::cout << ARR_array2[i].y << "=="
		<< ARR_array1[i].y << std::endl;
		
		std::cout << &ARR_array2[i] << "!="
		<< &ARR_array1[i] << std::endl;
	}

}  
