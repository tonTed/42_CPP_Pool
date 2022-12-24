/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:36:03 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 11:58:21 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){}

Weapon::~Weapon(){}

std::string	const	&Weapon::getType() const{ return (this->_type); }

void				Weapon::setType(std::string const type){ this->_type = type; }
