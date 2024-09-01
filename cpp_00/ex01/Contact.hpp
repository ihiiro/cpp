/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:16:35 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/08/31 18:56:07 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		Contact(std::string fn, std::string ln, std::string nn,
			std::string pn, std::string ds);
		std::string get_fn();
		std::string get_ln();
		std::string get_nn();
		std::string get_pn();
		std::string get_ds();
};