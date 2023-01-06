/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:11:29 by tonted            #+#    #+#             */
/*   Updated: 2023/01/06 13:51:27 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cfloat>
#include <cmath>
#include <ios>
#include <iostream>
#include <limits>
#include <float.h>
#include <sstream>

int main(int ac, char *av[])
{
    // double max = std::numeric_limits<double>::max();
    // double inf = std::numeric_limits<double>::infinity();

    // double  test = DBL_MAX + 1;

    // std::cout << isinf(test) << std::endl;
 
    // if(inf > max)
    //     std::cout << inf << " is greater than " << max << '\n';


    std::stringstream	ss;

	double	_double;

	ss << av[1];
    ss >> _double;
    
	int		_int = static_cast<int>(_double);
	char	_char = static_cast<char>(_double);
	float	_float= static_cast<float>(_double);

		std::cout << "double: " << std::fixed <<  _double << std::endl;
        std::cout << "int: " << std::fixed <<  _int << std::endl;
        std::cout << "float: " << std::fixed <<  _float << std::endl;
        std::cout << "char: " <<  std::fixed << _char << std::endl;



    // std::cout << std::fixed << FLT_MAX << std::endl;
    // std::cout << std::fixed << DBL_MAX << std::endl;
    // std::cout << std::fixed << LDBL_MAX << std::endl;

}