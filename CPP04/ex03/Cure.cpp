/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:07:51 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 13:09:35 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){
	std::cout << "A Cure Materia has been constructed" << std::endl;
};

Cure::Cure(Cure const & src){ *this = src; };

Cure::~Cure(void){

	std::cout << "A Cure Materia has been destructed" << std::endl;
};

Cure & Cure::operator=(Cure const & src){

	if (this != &src){
		AMateria::type = "cure";
	};

	return (*this);
};

void	Cure::use(ICharacter& target){
	
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria*	Cure::clone() const {

	AMateria*	ret = new Cure();

	return (ret);
};
