/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:49:00 by tonted            #+#    #+#             */
/*   Updated: 2022/12/07 16:18:59 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _number(0) {

	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(Fixed const & src){

	std::cout << "Copy constructor called" << std::endl;

	*this = src;
};

Fixed::~Fixed( void ){

	std::cout << "Destructor called" << std::endl;
};

Fixed &	Fixed::operator=(Fixed const & rhs){

	std::cout << "Copy assignment operator called" << std::endl;
	
	if(this != &rhs){
		this->_number = rhs.getRawBits();
	};
	return (*this);
}

/* GETTERS */
int		Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	
	return (this->_number);
};


/* SETTERS */
void	Fixed::setRawBits(int const number){
	this->_number = number;
};

int const Fixed::_decimals = 8;
