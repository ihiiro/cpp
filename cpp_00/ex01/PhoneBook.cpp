/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:36:47 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/07 16:45:33 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook(): index(0){}

void PhoneBook::add_contact(std::string fn, std::string ln,
	std::string nn, std::string pn, std::string ds)
{
	if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || ds.empty())
		return;
	if (index >= 8)
		contacts[index % 8] = Contact(fn, ln, nn, pn, ds);
	else
		contacts[index] = Contact(fn, ln, nn, pn, ds);
	index += 1;
}

Contact *PhoneBook::get_contacts()
{
	return (contacts);
}

Contact PhoneBook::search(int in)
{
	if (in < 0 || in >= 8)
		return (Contact("", "", "", "", ""));
	return (contacts[in]);
}
