/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormHighException.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:25:21 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/12/31 19:27:32 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>

class FormHighException: public std::exception
{
	public:
		const char *what() const throw();
};