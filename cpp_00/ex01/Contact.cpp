/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:53:21 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/08/31 18:55:23 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"

std::string Contact::get_fn()
{
	return (first_name);
}

std::string Contact::get_ln()
{
	return (last_name);
}

std::string Contact::get_nn()
{
	return (nickname);
}

std::string Contact::get_pn()
{
	return (phone_number);
}

std::string Contact::get_ds()
{
	return (darkest_secret);
}

Contact::Contact(): first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret(""){}

Contact::Contact(std::string fn, std::string ln, std::string nn,
	std::string pn, std::string ds)
{
	first_name = fn;
	last_name = ln;
	nickname = nn;
	phone_number = pn;
	darkest_secret = ds;
}
