/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:14:30 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 13:15:09 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("Ice"){
	std::cout << "A Ice Materia has been constructed" << std::endl;
};

Ice::Ice(Ice const & src){ *this = src; };

Ice::~Ice(void){

	std::cout << "A Ice Materia has been destructed" << std::endl;
};

Ice & Ice::operator=(Ice const & src){

	if (this != &src){
		AMateria::type = "Ice";
	};

	return (*this);
};

void	Ice::use(ICharacter& target){
	
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone() const {

	AMateria*	ret = new Ice();

	return (ret);
};