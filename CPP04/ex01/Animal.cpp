/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:05:09 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 21:24:07 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void){

	std::cout << "An animal has been constructed" << std::endl;
};

Animal::Animal(Animal const & src){ *this = src; };

Animal::~Animal(void){

	std::cout << "An animal has been destructed" << std::endl;
};

Animal &	Animal::operator=(Animal const & src){

	if (this != &src){
		this->type = src.type;
	}
	return (*this);
};

void	Animal::makeSound(void) const {

	std::cout << "A sound of an unknown animal!" << std::endl;
}

std::string const & Animal::getType(void) const {

	return (this->type);
};