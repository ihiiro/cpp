/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:12:22 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/02 19:12:38 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	/* bureaucrats */
	Bureaucrat president(5, "president");
	Bureaucrat vice(2, "vice");
	/* forms */
	PresidentialPardonForm pardon("Xavier renegade angel");
	RobotomyRequestForm lobotomy("Akhannouch");
	ShrubberyCreationForm idkman("trees ig?");
	/* vice signs pardon */
	vice.signForm(pardon);
	/* president executes the form */
	try
	{
		president.executeForm(pardon);
	}
	catch (char const *e)
	{
		std::cout << e << std::endl;
	}
	std::cout << "==============================================" << std::endl;
	/* new vice and president */
	for (; president.getGrade() != 45; president.dec());
	for (; vice.getGrade() != 72; vice.dec());
	/* vice signs lobotomy */
	vice.signForm(lobotomy);
	/* president executes the form */
	president.executeForm(lobotomy);
	std::cout << "==============================================" << std::endl;
	/* new vice and president */
	for (; president.getGrade() != 137; president.dec());
	for (; vice.getGrade() != 145; vice.dec());
	/* vice signs lobotomy */
	vice.signForm(idkman);
	/* president executes the form */
	president.executeForm(idkman);
}