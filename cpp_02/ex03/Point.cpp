/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:44:21 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/25 19:22:05 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0)
{
	
}

Point::Point(const float a, const float b): x(a), y(b)
{
	
}

Point::Point(const Point& p)
{
	(void)p;
}

Point& Point::operator= (const Point &f)
{
	(void)f;
	return ((Point&)f);
}

Point::~Point()
{
	
}

Fixed Point::getx() const
{
	return x;
}

Fixed Point::gety() const
{
	return y;
}