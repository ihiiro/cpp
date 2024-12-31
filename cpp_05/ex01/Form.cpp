/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:14:25 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/31 19:06:39 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*==================================*/
/*==================================*/
/* COMMON */
Form::Form(): name("default"), signer(MIN), executive(MIN)
{
	sign_ed = 0;
}
Form::Form(std::string nm, int sign_er, int executi_ve):
name(nm), signer(sign_er), executive(executi_ve)
{
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
}