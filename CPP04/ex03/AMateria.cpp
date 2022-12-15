/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:48:41 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 21:38:19 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void){};

AMateria::AMateria(std::string const & type) : type(type){
	std::cout << "A Materia has been constructed" << std::endl;
};

AMateria::AMateria(AMateria const & src){ *this = src; };

AMateria::~AMateria(void){

	std::cout << "A Materia has been destructed" << std::endl;
};

AMateria & AMateria::operator=(AMateria const & src){

	if (this != &src){
		this->type = src.type;
	}

	return (*this);
};

std::string const & AMateria::getType() const {
	return (type);
}
