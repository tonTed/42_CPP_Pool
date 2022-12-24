/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:29:38 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 11:21:29 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Crée un zombie, lui donne un nom et le retourne afin qu’il puisse être
 * utilisé en dehors de la portée de la fonction.
 * 
 * @param name 
 * @return Zombie* 
 */
Zombie* newZombie( std::string name ){
	return (new Zombie(name));
}
