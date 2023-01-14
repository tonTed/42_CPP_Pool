/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:26:41 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/14 11:50:36 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
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
	
	bool		isPseudoLiteral(void);
	bool		setFlag(void);
	
	void		convertAll(void);

	void		fromChar(void);
	void		fromInt(void);
	void		fromFloat(void);
	void		fromDouble(void);

	void		printImpossible(void);

	std::string	_literal;
	char		_flag;

	static	std::string const	_pseudoLiterals[8];

};

std::ostream &	operator<<(std::ostream & o, Converter const i);