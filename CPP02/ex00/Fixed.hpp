/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:35:46 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 13:59:35 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed{

public:
	Fixed( void );
	Fixed(Fixed const & src);
	~Fixed( void );

	Fixed &	operator=(Fixed const & rhs);

	/* GETTERS */
	int		getRawBits( void ) const;

	/* SETTERS */
	void	setRawBits(int const raw);

private:
	int					_number;
	static int const	_decimals;
};