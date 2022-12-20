/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:26:41 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/20 10:34:21 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define BAD_INPUT 0x0
#define T_CHAR 0x1
#define T_INT 0x2
#define T_FLOAT 0x4
#define T_DOUBLE 0x8

class Converter {

public:
	Converter(std::string literal);
	Converter(Converter const & src);
	~Converter(void);

	Converter&	operator=(Converter const & src);

private:
	Converter(void);
	
	void	setFlag(void);

	char		_flag;
	std::string	_char;
	int			_int;
	float		_float;
	double		_double;

};