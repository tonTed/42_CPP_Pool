/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:38:04 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/27 21:24:27 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <algorithm>
#include <iostream>
#include <ostream>

/*
https://www.youtube.com/watch?v=yTRzfKh4Tg0
https://www.gamedev.net/forums/topic.asp?topic_id=295943
https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
*/


Fixed CalcTriArea(Point const & p1, Point const & p2, Point const & p3)
{
	Fixed det;

	det = p1.getX() * (p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getX()) + p3.getX() * (p1.getY() - p2.getY());

	return (det > 0 ? det / Fixed(2) : det * - 1 / Fixed(2));
}

bool	bsp(Point const & a, Point const & b, Point const & c, Point const & point){

	
	Fixed TotalArea = CalcTriArea(a, b, c);
	Fixed Area1 = CalcTriArea(point, b, c);
	Fixed Area2 = CalcTriArea(point, a, c);
	Fixed Area3 = CalcTriArea(point, a, b);

	return (Area1 + Area2 + Area3 != TotalArea) ? false : true ;
}
