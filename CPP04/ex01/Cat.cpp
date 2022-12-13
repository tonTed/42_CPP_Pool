/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:54:15 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 21:55:48 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat(void) : _brain(new Brain) {

	type = "cat";
	std::cout << "A Cat has been constructed" << std::endl;
};

Cat::Cat(Cat const & src){ *this = src; };

Cat::~Cat(void){

	delete _brain;
	std::cout << "A Cat has been destructed" << std::endl;
};

Cat&	Cat::operator=(Cat const & src){

	if (this != &src){

		this->type = src.type;
	}
	return (*this);
};

void	Cat::makeSound(void) const {

	std::cout << "miaou!!!" << std::endl;
};
