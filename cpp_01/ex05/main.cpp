/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:24:04 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/03 05:47:32 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl complainer;

	complainer.complain("INFO");
	complainer.complain("WARNING");
	complainer.complain("ERROR");
	complainer.complain("DEBUG");
	complainer.complain("unrecognized");
}