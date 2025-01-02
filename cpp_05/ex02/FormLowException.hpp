/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormLowException.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:25:25 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/31 19:27:14 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>

class FormLowException: public std::exception
{
	public:
		const char *what() const throw();
};