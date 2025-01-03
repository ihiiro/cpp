/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:12:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/02 19:53:20 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
/*==================================*/
/*==================================*/
/* COMMON */
RobotomyRequestForm::RobotomyRequestForm()
{
	setName("RobotomyRequestForm");
	setSigned(0);
	setSigner(72);
	setExecutive(45);
	setTarget("default");
}
RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
	setName("RobotomyRequestForm");
	setSigned(0);
	setSigner(72);
	setExecutive(45);
	setTarget(target);
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
{
	setTarget(obj.getTarget());
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this != &obj)
		setTarget(obj.getTarget());
	return *this;
}
/*==================================*/
RobotomyRequestForm::~RobotomyRequestForm(){}
/*==================================*/
/* NON-MODIFIERS */
void RobotomyRequestForm::execute_() const
{
	std::cout << "*** (drilling noises) ***" << std::endl;
	std::srand(std::time(NULL));
	std::cout << "Robotomy on " << getTarget();
	if ((std::rand() % 2) == 0)
		std::cout << " succeeded!";
	else
		std::cout << " failed :/";
	std::cout << std::endl;
}