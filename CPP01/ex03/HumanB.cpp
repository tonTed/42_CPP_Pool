/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:15:48 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 12:01:51 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){}

HumanB::~HumanB(){}

void	HumanB::attack() const{
	std::cout << this->_name + " attacks with their " + this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon *weapon){ this->_weapon = weapon; }