/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:44:27 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/11/25 19:20:14 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float ABS(float f)
{
	if (f < 0)
		return -f;
	return f;
}

bool equal(float a, float b)
{
	return ABS(a - b) < .0001;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	// vertices
	Fixed ax = a.getx();
	Fixed ay = a.gety();
	Fixed bx = b.getx();
	Fixed by = b.gety();
	Fixed cx = c.getx();
	Fixed cy = c.gety();
	// point
	Fixed px = point.getx();
	Fixed py = point.gety();

	float triangle_area = ABS((ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2);
	float pbc = ABS((px * (by - cy) + bx * (cy - py) + cx * (py - by)) / 2);
	float pac = ABS((ax * (py - cy) + px * (cy - ay) + cx * (ay - py)) / 2);
	float pab = ABS((ax * (by - py) + bx * (py - ay) + px * (ay - by)) / 2);
	
	// point is on an edge or is a vertex
	if (equal(pac, 0) or equal(pab, 0) or equal(pbc, 0))
		return (false);
	return equal(triangle_area, pbc + pac + pab);
}