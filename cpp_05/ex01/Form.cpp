/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:14:25 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/31 20:01:40 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*==================================*/
/*==================================*/
/* COMMON */
Form::Form(): name("default"), signer(MIN), executive(MIN)
{
	sign_ed = 0;
}
Form::Form(char const *nm, int sign_er, int executi_ve):
name(nm), signer(sign_er), executive(executi_ve)
{
	if (sign_er < 1 or executi_ve < 1)
		throw FormHighException();
	if (sign_er > 150 or executi_ve > 150)
		throw FormLowException();
	sign_ed = 0;
}
Form::Form(const Form &obj):
name(obj.name), signer(obj.signer), executive(obj.executive)
{
	sign_ed = obj.sign_ed;
}
Form& Form::operator=(const Form &obj)
{
	if (this != &obj)
		sign_ed = obj.sign_ed;
	return *this;
}
/*==================================*/
Form::~Form(){}
/*==================================*/
/* GETTERS */
std::string Form::getName() const
{
	return name;
}
bool Form::getSigned() const
{
	return sign_ed;
}
int Form::getSigner() const
{
	return signer;
}
int Form::getExecutive() const
{
	return executive;
}
/*==================================*/
/*==================================*/
/* MODIFIERS */
void Form::beSigned(Bureaucrat const &obj)
{
	if (obj.getGrade() <= signer)
		sign_ed = 1;
	else
		throw FormLowException();
}
/*==================================*/
/*==================================*/
/* EXTERNAL OVERLOADS */
std::ostream& operator<< (std::ostream &out, Form const &obj)
{
	out << "FORM{" << obj.getName() << "," << obj.getSigned() <<
	"," << obj.getSigner() << "," << obj.getExecutive() << "}" << std::endl;
	return out;
}