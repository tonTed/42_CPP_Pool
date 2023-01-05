/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:35:14 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/05 10:36:18 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void){};

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name + "_clap_name"), _name(name) {

	this->_hitPoints = FragTrap::HIT_POINTS;
	this->_energyPoints = ScavTrap::ENERGY_POINTS;
	this->_attackDamage = FragTrap::ATTACK_DAMAGE;
	std::cout << "DiamondTrap " + name + " has been constructed." << std::endl;
};

DiamondTrap::DiamondTrap(DiamondTrap const & src){ *this = src; };

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & rhs){
	
	if(this != &rhs){
		std::cout << "DiamondTrap " + rhs._name + " has been copied." << std::endl;
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage; 
	};
	return (*this);
}

void	DiamondTrap::attack(const std::string &target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() const
{
    std::cout << "ClapTrap: " << ClapTrap::_name << "| DiamondTrap: " << _name << '\n';
}

DiamondTrap::~DiamondTrap(void){

	std::cout << "DiamondTrap " + _name + " has been destructed." << std::endl;
};

std::ostream &	operator<<(std::ostream & o, DiamondTrap const & i){
	o << "\nDiamondTrap [ " + i.getName() + " ]" << std::endl;
	o << "\t{life: " << i.getHitPoints() << " - Energy: " << i.getEnergyPoints() <<
	" - Damage: " << i.getAttackeDamage() << "}." << std::endl;

	return (o);
};