/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:50:44 by yel-yaqi          #+#    #+#             */
/*   Updated: 2025/01/11 00:44:58 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <inttypes.h>
#include <iostream>

typedef struct data
{
	int x;
	int y;
	int z;
}		Data;

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const& obj);
		Serializer& operator=(Serializer const& obj);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		~Serializer();
};