/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormHighException.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:25:21 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/05 12:51:45 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>


// base class
class A
{
	private:
		int n;
	public:
		void hello();
};

// child class
class B: protected A
{
	private:
		int n;
	protected:
		void hello();
};

class FormHighException: public std::exception
{
	public:
		
	public:
		const char *what() const throw();
};