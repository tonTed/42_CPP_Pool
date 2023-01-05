/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:08:15 by tonted            #+#    #+#             */
/*   Updated: 2023/01/05 10:56:44 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){

	type = "dog";
	std::cout << "A Dog has been constructed" << std::endl;
};

Dog::Dog(Dog const & src){ *this = src; };

Dog::~Dog(void){

	std::cout << "A Dog has been destructed" << std::endl;
};

Dog&	Dog::operator=(Dog const & src){

	if (this != &src){
		this->type = src.type;
	}
	return (*this);
};

void	Dog::makeSound(void) const {

	std::cout << "Wouaf Wouaf!!" << std::endl;
};
