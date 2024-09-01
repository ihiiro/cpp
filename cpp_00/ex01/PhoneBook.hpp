/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:16:05 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/01 15:09:18 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		index;
	public:
		PhoneBook();
		void add_contact(std::string fn, std::string ln,
			std::string nn, std::string pn, std::string ds);
		Contact search(int in);
		Contact *get_contacts();
};