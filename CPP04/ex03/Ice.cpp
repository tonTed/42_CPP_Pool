/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:14:30 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 21:29:07 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){
	std::cout << "A Ice Materia has been constructed" << std::endl;
};

Ice::Ice(Ice const & src){ *this = src; };

Ice::~Ice(void){

	std::cout << "A Ice Materia has been destructed" << std::endl;
};

Ice & Ice::operator=(Ice const & src){

	if (this != &src){
		AMateria::type = "ice";
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