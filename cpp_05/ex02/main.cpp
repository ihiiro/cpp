/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:12:22 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/02 18:47:36 by yel-yaqi         ###   ########.fr       */
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
	/* vice signs pardon */
	vice.signForm(pardon);
	/* president executes the form */
	president.executeForm(pardon);
	/* new vice and president */
	// for (; president.getGrade() != 137; president.dec());
	// for (; vice.getGrade() != 145; president.dec());
	// /* vice signs lobotomy */
	// vice.signForm(lobotomy);
	// /* president executes the form */
	// president.executeForm(lobotomy);
}