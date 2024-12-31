/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:14:21 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/31 19:08:01 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Bureaucrat.hpp"

/*==================================*/
/*==================================*/
/* CLASSES */
class Form
{
	private:
		std::string const name;
		bool sign_ed;
		int const signer;
		int const executive;
	public:
		/*==================================*/
		/* COMMON */
		Form();
		Form(std::string nm, int sign_er, int executi_ve);
		~Form();
		Form(const Form &obj);
		Form& operator=(const Form &obj);
		/*==================================*/
		/* GETTERS */
		std::string getName() const;
		bool getSigned() const;
		int getSigner() const;
		int getExecutive() const;
		/*==================================*/
		/* MODIFIERS */
		void beSigned(Bureaucrat const &obj);
		/*==================================*/
		/* EXCEPTIONS */
		static GradeTooHighException gth;
		static GradeTooLowException gtl;
};
/*==================================*/
/*==================================*/
/* EXTERNAL OVERLOADS */
std::ostream& operator<< (std::ostream &out, Form const &obj);