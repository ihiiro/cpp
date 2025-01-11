/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:55:24 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/11 01:36:48 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main()
{
	/* using identify(Base*) */
	Base* ptrA = new A;
	Base* ptrB = new B;
	Base* ptrC = new C;

	identify(ptrA);
	identify(ptrB);
	identify(ptrC);

	std::cout << "=========================" << std::endl;
	
	/* using identify(Base&) */
	Base& refA = *ptrA;
	Base& refB = *ptrB;
	Base& refC = *ptrC;
	identify(refA);
	identify(refB);
	identify(refC);
	
	std::cout << "=========================" << std::endl;


	/* generate() */
	Base* gen = generate();
	identify(gen);


	delete ptrA; delete ptrB; delete ptrC; delete gen;
}








Base* generate()
{
	std::srand(std::time(NULL));
	int n = rand() % 3; // range is between 0 and 2
	switch (n)
	{
		case 0: return new A;
		case 1: return new B;
		default: return new C;
	}
}









void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}











void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception&)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::exception&)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::exception&)
			{
				return;
			}
		}
	}
}