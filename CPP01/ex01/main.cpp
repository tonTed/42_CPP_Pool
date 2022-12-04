/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:42:41 by tonted            #+#    #+#             */
/*   Updated: 2022/12/04 14:52:38 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main( void )
{
	int	amount_zombies = 10;

	Zombie	*horde = zombieHorde(amount_zombies, "Foo");

	for (int i = 0; i < amount_zombies; i++)
		horde[i].announce();

	delete [] horde;
	return 0;
}
