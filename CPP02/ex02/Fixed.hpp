/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:35:46 by tonted            #+#    #+#             */
/*   Updated: 2022/12/07 18:38:32 by tonted           ###   ########.fr       */
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

	Fixed &	operator=(Fixed const & rhs);

	/* GETTERS */
	int		getRawBits( void ) const;

	/* SETTERS */
	void	setRawBits(int const number);

	/* CONVERTERS */
	float	toFloat() const;
	int		toInt() const;

private:
	int					_number;
	static int const	_decimals;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);