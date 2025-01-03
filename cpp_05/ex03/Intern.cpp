/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:08:43 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/03 18:34:41 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
/*==================================*/
/*==================================*/
/* COMMON */
/*==================================*/
Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(Intern const &Intern){ (void)Intern; }
Intern &Intern::operator=(Intern const &intern){ (void)intern; return *this; }
/*==================================*/
/* PURPOSE METHOD SERVERS */
static AForm *returnPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}
static AForm *returnRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}
static AForm *returnShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}
/*==================================*/
/*==================================*/
/* PURPOSE METHOD */
AForm *Intern::makeForm(std::string form, std::string target)
{
	AForm *(*forms[])(std::string target) = {&returnPresidentialPardonForm,
											&returnRobotomyRequestForm,
											&returnShrubberyCreationForm};
	std::string names[] = {"presidential pardon", "robotomy request",
							"shrubbery creation",
							};
	for (int i = 0; i < 3; i++)
		if (form == names[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return forms[i](target);
		}
	std::cout << "Intern couldn't find a form with name " << form << std::endl;
	return NULL;
}