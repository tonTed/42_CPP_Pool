/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:35:14 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/09 13:31:32 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ){};

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), _name(name){
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
};

DiamondTrap::DiamondTrap(DiamondTrap const & src){ *this = src; };

DiamondTrap::~DiamondTrap( void ){};

std::ostream &	operator<<(std::ostream & o, DiamondTrap const & i){
	o << "\nDiamondTrap [ " + i.getName() + " ]" << std::endl;
	o << "\t{life: " << i.getHitPoints() << " - Energy: " << i.getEnergyPoints() <<
	" - Damage: " << i.getAttackeDamage() << "}." << std::endl;

	return (o);
};