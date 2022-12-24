/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:48:24 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 11:21:13 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name){}

Zombie::~Zombie(){ std::cout << this->_name + ": has been deleted!" << std::endl; }

void	Zombie::announce( void ) const{
	std::cout << this->_name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}
