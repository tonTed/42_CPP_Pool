/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:08:15 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 22:08:01 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : _brain(new Brain) {

	type = "dog";
	std::cout << "A Dog has been constructed" << std::endl;
};

Dog::Dog(Dog const & src){ *this = src; };

Dog::~Dog(void){

	delete _brain;
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
