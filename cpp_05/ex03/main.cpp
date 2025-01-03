/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:12:22 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/03 18:44:14 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	/* intern and forms */
	AForm *form;
	Intern intern;
	/* bureaucrats */
	Bureaucrat president(5, "president");
	Bureaucrat vice(2, "vice");
	form = intern.makeForm("presidential pardon", "Xavier renegade angel");
	/* vice signs pardon */
	vice.signForm(*form);
	/* president executes the form */
	try
	{
		president.executeForm(*form);
	}
	catch (char const *e)
	{
		std::cout << e << std::endl;
	}
	std::cout << "==============================================" << std::endl;
	delete form;
	form = intern.makeForm("robotomy request", "Akhannouch");
	/* new vice and president */
	for (; president.getGrade() != 45; president.dec());
	for (; vice.getGrade() != 72; vice.dec());
	/* vice signs lobotomy */
	vice.signForm(*form);
	/* president executes the form */
	president.executeForm(*form);
	std::cout << "==============================================" << std::endl;
	delete form;
	form = intern.makeForm("shrubbery creation", "trees ig?");
	/* new vice and president */
	for (; president.getGrade() != 137; president.dec());
	for (; vice.getGrade() != 145; vice.dec());
	/* vice signs lobotomy */
	vice.signForm(*form);
	/* president executes the form */
	president.executeForm(*form);
	/* intern attempts to create a non-existent form  */
	std::cout << "==============================================" << std::endl;
	intern.makeForm("someshi", "whatever");
	delete form;
}