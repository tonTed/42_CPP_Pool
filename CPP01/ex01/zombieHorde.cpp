/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:16:58 by tonted            #+#    #+#             */
/*   Updated: 2022/12/04 14:44:37 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Cette fonction doit allouer N objets Zombie en une seule allocation.
 *  Ensuite, elle doit initialiser les zombies en donnant à chacun le nom passé
 *  en paramètre. Elle retourne un pointeur sur le premier zombie.
 * 
 * @param N
 * @param name 
 * @return Zombie* 
 */
Zombie* zombieHorde( int N, std::string name ){
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	
	return (horde);
}