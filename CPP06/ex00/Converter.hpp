/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:26:41 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/23 17:54:11 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ostream>

#define BAD_INPUT 0x0
#define T_CHAR 0x1
#define T_INT 0x2
#define T_FLOAT 0x4
#define T_DOUBLE 0x8
#define NEG 0x10

class Converter {

public:
	Converter(std::string literal);
	Converter(Converter const & src);
	~Converter(void);

	Converter&	operator=(Converter const & src);

	void	printConversions(void);

private:
	Converter(void);
	
	void		setFlag(void);
	void		convertAll(void);
	char		convertToChar(void);

	std::string	_literal;
	char		_flag;

	std::string	_charOut;
	std::string	_intOut;
	std::string	_floatOut;
	std::string	_doubleOut;

	char		_char;
	int			_int;
	float		_float;
	double		_double;

};

std::ostream &	operator<<(std::ostream & o, Converter const i);