/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:35:46 by tonted            #+#    #+#             */
/*   Updated: 2022/12/07 16:18:10 by tonted           ###   ########.fr       */
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
	void	setRawBits(int const number);

private:
	int					_number;
	static int const	_decimals;
};