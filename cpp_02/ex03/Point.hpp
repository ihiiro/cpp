/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:44:23 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/25 19:21:42 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"
#include <stdbool.h>

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float a, const float b);
		Point(const Point& p);
		// assignment
		Point& operator= (const Point &f);
		//
		Fixed getx() const;
		Fixed gety() const;
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);