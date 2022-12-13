/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:05:09 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 22:17:57 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void){

	std::cout << "An AAnimal has been constructed" << std::endl;
};

AAnimal::AAnimal(AAnimal const & src){ *this = src; };

AAnimal::~AAnimal(void){

	std::cout << "An AAnimal has been destructed" << std::endl;
};

AAnimal &	AAnimal::operator=(AAnimal const & src){

	if (this != &src){
		this->type = src.type;
	}
	return (*this);
};

void	AAnimal::makeSound(void) const {

	std::cout << "A sound of an unknown AAnimal!" << std::endl;
}

std::string const & AAnimal::getType(void) const {

	return (this->type);
};