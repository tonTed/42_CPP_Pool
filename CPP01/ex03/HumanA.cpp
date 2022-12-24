/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:41:57 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 11:59:45 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){}

HumanA::~HumanA(){}

void	HumanA::attack() const{
	std::cout << this->_name + " attacks with their " + this->_weapon.getType() << std::endl;
}
