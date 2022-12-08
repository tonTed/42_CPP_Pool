/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:32:36 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/08 17:07:02 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	player1(std::string("Player1"));
	ClapTrap	player2(std::string("Player2"));
	ClapTrap	player3(player1);

	player1.attack("enemy");
	player2.takeDamage(3);
	player1.takeDamage(2);
	player1.beRepaired(5);
	player2.takeDamage(9);
	player2.attack("enemy");

	std::cout << player1 << std::endl;
	std::cout << player2 << std::endl;

	return 0;
}