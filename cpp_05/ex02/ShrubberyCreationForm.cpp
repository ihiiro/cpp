/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:40 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/02 19:34:23 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
/*==================================*/
/*==================================*/
/* COMMON */
ShrubberyCreationForm::ShrubberyCreationForm()
{
	setName("ShrubberyCreationForm");
	setSigned(0);
	setSigner(145);
	setExecutive(137);
	setTarget("default");
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
	setName("ShrubberyCreationForm");
	setSigned(0);
	setSigner(145);
	setExecutive(137);
	setTarget(target);
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
{
	setTarget(obj.getTarget());
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this != &obj)
		setTarget(obj.getTarget());
	return *this;
}
/*==================================*/
ShrubberyCreationForm::~ShrubberyCreationForm(){}
/*==================================*/
/* NON-MODIFIERS */
void ShrubberyCreationForm::execute_() const
{
	std::ofstream stream(getTarget() + "_shrubbery");
	stream << "			//////\n";
	stream << "		//////////////\n";
	stream << "	//////////////////////\n";
	stream << "///////////////////////////////\n";
	stream << "			//\n";
	stream << "			//\n";
	stream << "			//\n";
	stream << "			//\n";
}