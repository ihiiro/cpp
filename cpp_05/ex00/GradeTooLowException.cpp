/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:01:31 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/31 19:12:03 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException.hpp"

const char *GradeTooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLowException";
}