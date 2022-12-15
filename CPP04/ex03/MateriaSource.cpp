/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:24:07 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 21:40:23 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <algorithm>
#include <cstddef>

MateriaSource::MateriaSource(void){

	for (size_t i = 0; i < 4; i++){ _inventory[i] = NULL; }
	
	std::cout << "MateriaSource has been constructed" << std::endl;
};

MateriaSource::MateriaSource(MateriaSource const & src){ *this = src; };

MateriaSource::~MateriaSource(void){

	for (size_t i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}

	std::cout << "MateriaSource has been destructed" << std::endl;
};


MateriaSource&	MateriaSource::operator=(MateriaSource const & src){

	if (this != &src){
		for (size_t i = 0; i < 4; i++)
		{
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i];
		}
	}

	return *this;
};

void	MateriaSource::learnMateria(AMateria* src){

	for (size_t i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = src;
			break;
		}
	}
};

AMateria* MateriaSource::createMateria(std::string const & type){
	
	(void)type;

	for (int i = 3; i >= 0; i--) {
		if (_inventory[i] && !_inventory[i]->getType().compare(type)){
			return _inventory[i]->clone();
		}
	}

	return NULL;
};
