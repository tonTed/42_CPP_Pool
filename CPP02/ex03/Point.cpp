/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:59:01 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/24 16:36:16 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)){};

Point::Point(float const & x, float const & y) : _x(Fixed(x)), _y(Fixed(y)) {};

Point::Point(Point const & src){ *this = src; };

Point::~Point(void){ };

Fixed const & Point::getX(void) const { return _x; };
Fixed const & Point::getY(void) const { return _y; };

Point &	Point::operator=(Point const & src){ (void)src; return *this; };
