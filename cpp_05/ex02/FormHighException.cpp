/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormHighException.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:25:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/31 19:28:30 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FormHighException.hpp"

const char *FormHighException::what() const throw()
{
	return "Form::GradeTooHighException";
}