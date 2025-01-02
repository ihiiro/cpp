/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:14:25 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/02 18:47:06 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
/*==================================*/
AForm::~AForm(){}
/*==================================*/
/* GETTERS */
std::string AForm::getName() const
{
	return name;
}
bool AForm::getSigned() const
{
	return signed__;
}
int AForm::getSigner() const
{
	return signer;
}
int AForm::getExecutive() const
{
	return executive;
}
std::string AForm::getTarget() const
{
	return target;
}
/*==================================*/
/*==================================*/
/* SETTERS */
void AForm::setName(std::string nm)
{
	name = nm;
}
void AForm::setSigned(bool signed_)
{
	signed__ = signed_;
}
void AForm::setSigner(int signer_)
{
	signer = signer_;
}
void AForm::setExecutive(int executive_)
{
	executive = executive_;
}
void AForm::setTarget(std::string target_)
{
	target = target_;
}
/*==================================*/
/*==================================*/
/* MODIFIERS */
void AForm::beSigned(Bureaucrat const &obj)
{
	if (obj.getGrade() <= signer)
		signed__ = 1;
	else
		throw FormLowException();
}
/*==================================*/
/*==================================*/
/* NON-MODIFIERS */
void AForm::execute(Bureaucrat const &executive_) const
{
	if (executive_.getGrade() > executive)
		throw FormLowException();
	if (!signed__)
		throw "Exception: form is not signed\n";
	this->execute_();
}
/*==================================*/
/*==================================*/
/* EXTERNAL OVERLOADS */
std::ostream& operator<< (std::ostream &out, AForm const &obj)
{
	out << obj.getName() << "{" << obj.getSigned() << ","
	<< obj.getSigner() << "," << obj.getExecutive() << "}"
	<< std::endl;
	return out;
}