/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2023/01/11 09:25:39 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <climits>
#include <cfloat>
#include <sstream>

int	main(int ac, char *av[]){


	if (ac != 2){
		std::cout << "Bad amounts of arguments(expected 1, given " << ac - 1 << ")" << std::endl;
		return 0;
	}

	Converter toConvert(av[1]);
	
	return 0;
}
