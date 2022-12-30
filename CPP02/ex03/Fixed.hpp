/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:35:46 by tonted            #+#    #+#             */
/*   Updated: 2022/12/30 08:20:50 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed{

public:
	Fixed( void );
	Fixed(int const number);
	Fixed(float const number);
	Fixed(Fixed const & src);
	~Fixed( void );

	/* ASSIGNEMENT OPERATOR */
	Fixed &	operator=(Fixed const & rhs);

	/* COMPARISON OPERATORS */
	bool	operator>(Fixed const & rhs) const;
	bool	operator<(Fixed const & rhs) const;
	bool	operator>=(Fixed const & rhs) const;
	bool	operator<=(Fixed const & rhs) const;
	bool	operator==(Fixed const & rhs) const;
	bool	operator!=(Fixed const & rhs) const;

	/* BINARY ARITHMETIC OPERATORS */
	Fixed	operator+(Fixed const & rhs) const;
	Fixed	operator-(Fixed const & rhs) const;
	Fixed	operator*(Fixed const & rhs) const;
	Fixed	operator/(Fixed const & rhs) const;

	/* INCREMENT DECREMENT OPERATORS */
	// ++a
	Fixed &	operator++(void);
	// a++
	Fixed	operator++(int);
	Fixed &	operator--(void);
	Fixed	operator--(int);

	bool	operator!(void);

	/* GETTERS */
	int		getRawBits( void ) const;

	/* SETTERS */
	void	setRawBits(int const number);

	/* CONVERTERS */
	float	toFloat() const;
	int		toInt() const;

	/* */
	static const Fixed &	min(Fixed const & lhs, Fixed const & rhs);
	static const Fixed &	max(Fixed const & lhs, Fixed const & rhs);

	static Fixed &	min(Fixed & lhs, Fixed & rhs);
	static Fixed &	max(Fixed & lhs, Fixed & rhs);


private:
	int					_number;
	static int const	_decimals;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);