/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:52:49 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/27 17:16:14 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"
#include <iterator>
#include <ostream>

class Point {

public:
	Point(void);
	Point(float const & x, float const & y);
	Point(Point const & src);
	~Point(void);

	Point &	operator=(Point const & src);

	Fixed const & getX(void) const;
	Fixed const & getY(void) const;

private: 
	Fixed const	_x;
	Fixed const	_y;

};

std::ostream&	operator<<(std::ostream & o, Point & i);