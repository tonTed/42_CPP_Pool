/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:56:11 by tonted            #+#    #+#             */
/*   Updated: 2022/12/04 14:12:53 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

int main()
{
	Zombie	*foo = newZombie("Foo");

	foo->announce();

	randomChump("FAA");

	delete foo;

	return 0;
}
