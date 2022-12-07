/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:49:00 by tonted            #+#    #+#             */
/*   Updated: 2022/12/07 18:40:37 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>
#include <bitset>

Fixed::Fixed( void ) : _number(0) {

	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(int const number){

	std::cout << "Int constructor called" << std::endl;
	this->_number = number << this->_decimals;
};

Fixed::Fixed(float const number){

	std::cout << "Float constructor called" << std::endl;
	this->_number = int(number * float(1 << this->_decimals) + (number >= 0 ? 0.5 : -0.5));
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
		this->_number = rhs._number;
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

/* CONVERTERS */
float Fixed::toFloat() const{

    return (float)this->_number / (float)(1 << this->_decimals);
}

int Fixed::toInt() const{
	
    return (this->_number >> this->_decimals);
}

int const Fixed::_decimals = 8;

std::ostream &	operator<<(std::ostream& s, Fixed const & i){
    s << i.toFloat();
    return (s);
}