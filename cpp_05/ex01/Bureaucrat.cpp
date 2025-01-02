/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 04:38:10 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/02 18:55:14 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*==================================*/
/*==================================*/
/* COMMON */
Bureaucrat::Bureaucrat(): name("default")
{
	grade = MIN;
}
Bureaucrat::Bureaucrat(int g, char const *nm): name(nm)
{
	if (g < 1)
		throw GradeTooHighException();
	if (g > 150)
		throw GradeTooLowException();
	grade = g;
}
Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.name)
{
	grade = obj.grade;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
		grade = obj.grade;
	return *this;
}
/*==================================*/
Bureaucrat::~Bureaucrat(){}
/*==================================*/
/* GETTERS */
std::string Bureaucrat::getName() const
{
	return name;
}
int Bureaucrat::getGrade() const
{
	return grade;
}
/*==================================*/
/*==================================*/
/* MODIFIERS */
void Bureaucrat::inc()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}
void Bureaucrat::dec()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}
/*==================================*/
/*==================================*/
/* NON-MODIFIERS */
void Bureaucrat::signForm(Form &obj)
{
	if (grade <= obj.getSigner())
	{
		std::cout << name << " signed " << obj.getName() << std::endl;
		obj.beSigned(*this);
	}
	else
		std::cout << name << " couldn't sign " << obj.getName()
		<< " because grade is too low" << std::endl;
}
/*==================================*/
/*==================================*/
/* EXTERNAL OVERLOADS */
std::ostream& operator<< (std::ostream &out, Bureaucrat const &obj)
{
	out << obj.getName() << ", " << "bureaucrat grade " << obj.getGrade()
	<< std::endl;
	return out;
}