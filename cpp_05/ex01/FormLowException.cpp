/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormLowException.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:25:23 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/31 19:28:54 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FormLowException.hpp"

const char *FormLowException::what() const throw()
{
	return "Form::GradeTooLowException";
}