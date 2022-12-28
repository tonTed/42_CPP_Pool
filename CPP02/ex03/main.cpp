/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:32:56 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/27 21:27:18 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const & a, Point const & b, Point const & c, Point const & point);

int main(void)
{
	
	Point a(0.0f, 0.0f);
	Point b(0.0f, 5.0f);
	Point c(5.0f, 0.0f);
	Point d(2.0f, 2.0f);
	Point e(3.0f, 2.5f);

	std::cout << std::boolalpha << bsp(a, b, c, d) << std::endl;
	std::cout << std::boolalpha << bsp(a, b, c, e) << std::endl;


	return 0;
} 