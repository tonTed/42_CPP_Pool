/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:54:15 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 20:00:13 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat(void){

	type = "WrongCat";
	std::cout << "A WrongCat has been constructed" << std::endl;
};

WrongCat::WrongCat(WrongCat const & src){ *this = src; };

WrongCat::~WrongCat(void){

	std::cout << "A WrongCat has been destructed" << std::endl;
};

WrongCat&	WrongCat::operator=(WrongCat const & src){

	if (this != &src){

		this->type = src.type;
	}
	return (*this);
};

void	WrongCat::makeSound(void) const {

	std::cout << "miaou!!!" << std::endl;
};
