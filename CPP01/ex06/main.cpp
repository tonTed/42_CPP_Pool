/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:25:27 by tonted            #+#    #+#             */
/*   Updated: 2022/12/05 11:46:10 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>

int main(int ac, char const *av[])
{
	if (ac != 2){
		std::cout << "The program needs 1 arguments (" << ac - 1 << " given)."
		<< std::endl;
		return (EXIT_FAILURE);
	}

	std::string	level = av[1];

	Harl	harl;

	harl.complainSwitch(level);
	return 0;
}
