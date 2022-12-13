/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:26:20 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/13 17:07:32 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : _name(name) {

	for (size_t i = 0; i < 4; i++){ inventory[i] = NULL; }
	std::cout << "Character has been constructed, hit name is: " << name << std::endl;
};

Character::Character(Character const & src) { *this = src; };

Character::~Character(void) {

	for (size_t i = 0; i < 4; i++){
		if(inventory[i])
			delete inventory[i];
	}
	
	std::cout << "Character " << _name << " has beed destructed" << std::endl;
};

Character &	Character::operator=(Character const & src) {
	
	if (this != &src){
		this->_name = src._name;
		for (size_t i = 0; i < 4; i++){
			if (src.inventory[i])
				this->inventory[i] = src.inventory[i]->clone();
		}
	}
	return (*this);
};

void Character::equip(AMateria* m) {
	for (size_t i = 0; i < 4; i++){
		if (!this->inventory[i]){
			this->inventory[i] = m;
			return ;
		}
	}
};

void Character::unequip(int idx) {
	if (idx >=0 && idx < 4){
		this->inventory[idx] = NULL;
	}
};

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4)
		inventory[idx]->use(target);
};

std::string const & Character::getName() const{
	return _name;
};