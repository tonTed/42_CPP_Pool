/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:49:00 by tonted            #+#    #+#             */
/*   Updated: 2022/12/30 08:25:56 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <math.h>
#include <bitset>

Fixed::Fixed( void ) : _number(0) {};

Fixed::Fixed(int const number){
	this->_number = number << this->_decimals;
};

Fixed::Fixed(float const number){
	this->_number = int(number * roundf(float(1 << this->_decimals)));
};

Fixed::Fixed(Fixed const & src){ *this = src; };

Fixed::~Fixed( void ){};

Fixed &	Fixed::operator=(Fixed const & rhs){
	
	if(this != &rhs){
		this->_number = rhs._number;
	};
	return (*this);
}

/* GETTERS */
int		Fixed::getRawBits( void ) const { return (this->_number); };


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

bool	Fixed::operator>(Fixed const & rhs) const {
	return (_number > rhs._number);
};

bool	Fixed::operator<(Fixed const & rhs) const {
	return (_number < rhs._number);
};

bool	Fixed::operator>=(Fixed const & rhs) const {
	return (_number >= rhs._number);
};

bool	Fixed::operator<=(Fixed const & rhs) const {
	return (_number <= rhs._number);
};

bool	Fixed::operator==(Fixed const & rhs) const {
	return (_number == rhs._number);
};

bool	Fixed::operator!=(Fixed const & rhs) const {
	return (_number != rhs._number);
};

Fixed	Fixed::operator+(Fixed const & rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
};

Fixed	Fixed::operator-(Fixed const & rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
};

Fixed	Fixed::operator*(Fixed const & rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
};

Fixed	Fixed::operator/(Fixed const & rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
};

Fixed &	Fixed::operator++(void){
	this->_number += 1;
	return (*this);
};

Fixed Fixed::operator++(int){
	Fixed old = *this;
	this->_number += 1;
	return (old);
};

Fixed &	Fixed::operator--(void){
	this->_number -= 1;
	return (*this);
};

Fixed Fixed::operator--(int){
	Fixed old = *this;
	this->_number -= 1;
	return (old);
};

bool	Fixed::operator!(void){
	return _number == 0 ? true : false;
}

Fixed const &	Fixed::min(Fixed const & lhs, Fixed const & rhs){

	if (lhs < rhs)
		return (lhs);
	return (rhs);
};
Fixed const &	Fixed::max(Fixed const & lhs, Fixed const & rhs){

	if (lhs > rhs)
		return (lhs);
	return (rhs);
};

Fixed &	Fixed::min(Fixed & lhs, Fixed & rhs){

	if (lhs < rhs)
		return (lhs);
	return (rhs);
};
Fixed &	Fixed::max(Fixed & lhs, Fixed & rhs){

	if (lhs > rhs)
		return (lhs);
	return (rhs);
};

int const Fixed::_decimals = 8;

std::ostream &	operator<<(std::ostream& s, Fixed const & i){
    s << i.toFloat();
    return (s);
}