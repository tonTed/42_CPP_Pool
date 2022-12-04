/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:29:36 by tonted            #+#    #+#             */
/*   Updated: 2022/12/04 13:58:14 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Crée un zombie, lui donne un nom et le fait se présenter.
 * 
 * @param name 
 */
void randomChump( std::string name ){
	Zombie zombie = Zombie(name);

	zombie.announce();
}
