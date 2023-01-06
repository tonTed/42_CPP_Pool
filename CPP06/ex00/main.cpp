/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2023/01/06 09:46:26 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <climits>
#include <cfloat>
#include <sstream>

// void print_byte_as_bits(char val) {
// 	for (int i = 7; 0 <= i; i--) {
// 		printf("%c", (val & (1 << i)) ? '1' : '0');
// 	}
//   std::cout << std::endl;
// }

int	main(int ac, char *av[]){


	if (ac != 2){
		std::cout << "Bad amounts of arguments(expected 1, given " << ac - 1 << ")" << std::endl;
		return 0;
	}

	// Converter toConvert(av[1]);

	std::stringstream	ss;

	int		_int;
	char	_char;
	float	_float;
	double	_double;

	ss << av[1];

	ss >> _int;		std::cout << "int: " << _int << std::endl;
	ss >> _char;	std::cout << "char: " << _char << std::endl;
	ss >> _float;	std::cout << "float: " << _float << std::endl;
	ss >> _double;	std::cout << "double: " << _double<< std::endl;

	
	return 0;
}
