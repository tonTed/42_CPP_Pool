/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:32:36 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/08 18:57:06 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap	p1(std::string("Ted"));

	std::cout << p1.getEnergyPoints() << std::endl;
	p1.attack("enemy");
	std::cout << p1.getEnergyPoints() << std::endl;
	p1.guardGate();
	std::cout << p1 << std::endl;


	return 0;
}