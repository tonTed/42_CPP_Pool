/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:48:24 by tonted            #+#    #+#             */
/*   Updated: 2022/12/04 14:41:44 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name){

}

Zombie::~Zombie(){

	std::cout << this->_name + ": has been deleted!" << std::endl;
}

void	Zombie::announce( void ) const{

	std::cout << this->_name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string const name){
	this->_name = name;
}
