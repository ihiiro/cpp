/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 04:38:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/02 18:52:31 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Form.hpp"

/*==================================*/
/*==================================*/
/* MACROS */
#ifndef MAX
#define MAX 1
#endif
#ifndef MIN
#define MIN 150
#endif
/*==================================*/
/*==================================*/
/* CLASS */
class Bureaucrat
{
	private:
		std::string const name;
		int grade;
	public:
		/*==================================*/
		/* COMMON */
		Bureaucrat();
		Bureaucrat(int g, const char *nm);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat& operator=(const Bureaucrat &obj);
		/*==================================*/
		/* MODIFIERS */
		void inc();
		void dec();
		/*==================================*/
		/* GETTERS */
		std::string getName() const;
		int getGrade() const;
		/*==================================*/
		/* NON-MODIFIERS */
		void signForm(Form &obj);
};
/*==================================*/
/*==================================*/
/* EXTERNAL OVERLOADS */
std::ostream& operator<< (std::ostream &out, Bureaucrat const &obj);