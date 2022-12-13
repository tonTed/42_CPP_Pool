/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:05:09 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 21:32:58 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){

	std::cout << "An WrongAnimal has been constructed" << std::endl;
};

WrongAnimal::WrongAnimal(WrongAnimal const & src){ *this = src; };

WrongAnimal::~WrongAnimal(void){

	std::cout << "An WrongAnimal has been destructed" << std::endl;
};

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src){

	if (this != &src){
		this->type = src.type;
	}
	return (*this);
};

void	WrongAnimal::makeSound(void) const {

	std::cout << "A sound of an unknown WrongAnimal!" << std::endl;
}

std::string const & WrongAnimal::getType(void) const {

	return (this->type);
};