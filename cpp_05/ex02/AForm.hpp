/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:14:21 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/02 18:50:40 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "FormHighException.hpp"
#include "FormLowException.hpp"
#include <iostream>

/* FORWARD */
class Bureaucrat;

/*==================================*/
/*==================================*/
/* CLASSES */
class AForm
{
	private:
		std::string name;
		bool signed__;
		int signer;
		int executive;
		std::string target;
	public:
		/*==================================*/
		virtual ~AForm();
		/*==================================*/
		/* GETTERS */
		std::string getName() const;
		bool getSigned() const;
		int getSigner() const;
		int getExecutive() const;
		std::string getTarget() const;
		/* SETTERS */
		void setName(std::string nm);
		void setSigned(bool signed_);
		void setSigner(int signer_);
		void setExecutive(int executive_);
		void setTarget(std::string target_);
		/*==================================*/
		/* MODIFIERS */
		void beSigned(Bureaucrat const &obj);
		/* NON-MODIFIERS */
		void execute(Bureaucrat const &executive_) const;
		virtual void execute_() const = 0;
};
/*==================================*/
/*==================================*/
/* EXTERNAL OVERLOADS */
std::ostream& operator<< (std::ostream &out, AForm const &obj);