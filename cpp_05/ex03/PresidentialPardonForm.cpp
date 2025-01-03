/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:10:20 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/02 19:54:44 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
/*==================================*/
/*==================================*/
/* COMMON */
PresidentialPardonForm::PresidentialPardonForm()
{
	setName("PresidentialPardonForm");
	setSigned(0);
	setSigner(25);
	setExecutive(5);
	setTarget("default");
}
PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
	setName("PresidentialPardonForm");
	setSigned(0);
	setSigner(25);
	setExecutive(5);
	setTarget(target);
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
{
	setTarget(obj.getTarget());
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this != &obj)
		setTarget(obj.getTarget());
	return *this;
}
/*==================================*/
PresidentialPardonForm::~PresidentialPardonForm(){}
/*==================================*/
/* NON-MODIFIERS */
void PresidentialPardonForm::execute_() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}