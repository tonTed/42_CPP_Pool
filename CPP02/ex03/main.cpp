/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:32:56 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/24 17:56:10 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const & a, Point const & b, Point const & c, Point const & point);

int main(void)
{
    
    Point a(0.0f,0.0f);
    Point b(0.0f, 5.0f);
    Point c(5.0f, 0.0f);
    Point d(2.5f, 2.0f);
    Point e(2, 2);

    std::cout << b.getX() << " " << b.getY() << std::endl;

    std::cout << std::boolalpha << bsp(a, b, c, d) << std::endl;
    // std::cout << std::boolalpha << bsp(a, b, c, e) << std::endl;

    // std::cout << e.getX() << " " << e.getY() << '\n';

    return 0;
} 