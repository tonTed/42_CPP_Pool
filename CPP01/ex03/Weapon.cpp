/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:36:03 by tonted            #+#    #+#             */
/*   Updated: 2022/12/04 15:59:15 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){

}

Weapon::~Weapon(){

}

std::string	const	&Weapon::getType() const{
	// std::string const &type = this->_type;
	// return (type);
	return (this->_type);
}

void				Weapon::setType(std::string const type){
	this->_type = type;
}
