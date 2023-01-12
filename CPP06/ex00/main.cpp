/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2023/01/12 18:36:09 by tonted           ###   ########.fr       */
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

	Converter toConvert(av[1]);

	return 0;
}
