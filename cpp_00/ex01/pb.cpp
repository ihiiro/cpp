/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:07:36 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/04 17:42:54 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void prompt_for_info(std::string *info)
{
	std::cout << "first name: ";
	std::getline(std::cin, info[0]);
	std::cout << "last name: ";
	std::getline(std::cin, info[1]);
	std::cout << "nickname: ";
	std::getline(std::cin, info[2]);
	std::cout << "phone number: ";
	std::getline(std::cin, info[3]);
	std::cout << "darkest secret: ";
	std::getline(std::cin, info[4]);
}

void display_9_chars(std::string str)
{
	for (int i = 0; i < 9; i++)
		std::cout << str[i];
	std::cout << '.';
}

void display_contacts(Contact *contacts)
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(50);
		std::cout << i << " | ";
		if (contacts[i].get_fn().length() > 10)
			display_9_chars(contacts[i].get_fn());
		else
			std::cout << contacts[i].get_fn();
		std::cout << " | ";
		if (contacts[i].get_ln().length() > 10)
			display_9_chars(contacts[i].get_ln());
		else
			std::cout << contacts[i].get_ln();
		std::cout << " | ";
		if (contacts[i].get_nn().length() > 10)
			display_9_chars(contacts[i].get_nn());
		else
			std::cout << contacts[i].get_nn();
		std::cout << '\n';
	}
}

void display_search_contact(Contact contact)
{
	std::cout << "FIRST NAME: " << contact.get_fn() << "\n";
	std::cout << "LAST NAME: " << contact.get_ln() << "\n";
	std::cout << "NICKNAME: " << contact.get_nn() << "\n";
	std::cout << "PHONE NUMBER: " << contact.get_pn() << "\n";
	std::cout << "DARKEST SECRET: " << contact.get_ds() << "\n";
}

bool is_all_digits(std::string str)
{
	std::string::iterator	index_it_begin = str.begin();
	std::string::iterator	index_it_end = str.end();

	if (*index_it_begin == '\0')
		return (false);
	for (; index_it_begin != index_it_end; index_it_begin++)
		if (*index_it_begin < 48 || *index_it_begin > 57)
			return (false);
	return (true);
}

int main()
{
	PhoneBook 				pb;
	std::string 			info[5];
	std::string 			index;
	
	Contact					search_contact;

	for (std::string action = ""; action != "EXIT";) //EOF
	{
		std::cout << "> ";
		std::getline(std::cin, action);
		if (std::cin.eof())
		{
			std::cout << "^D\n";
			return (0);
		}
		if (action == "ADD") 
		{
			prompt_for_info(info);
			pb.add_contact(info[0], info[1], info[2], info[3], info[4]);
		}
		else if (action == "SEARCH")
		{
			display_contacts(pb.get_contacts());
			std::cout << "INDEX > ";
			std::getline(std::cin, index);
			if (!is_all_digits(index))
				continue;
			search_contact = pb.search(std::atoi(index.c_str()));
			if (search_contact.get_fn() != "")
				display_search_contact(search_contact);
			else
				std::cout << "index out of range or list empty.\n";
		}
	}
}
