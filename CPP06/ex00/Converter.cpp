/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:30:16 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/11 17:35:49 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <ios>
#include <iostream>
#include <ostream>

Converter::Converter(std::string literal){
	
	_literal << literal;
	_literal >> _longDouble;

	std::cout << "FAIL? -> " << std::boolalpha << _literal.fail() << std::endl;

	printConversions(literal);
};

Converter::Converter(Converter const & src){ *this = src; };

Converter::~Converter(void){};

Converter&	Converter::operator=(Converter const & src){

	if (this != &src)
	{
		_literal << src._literal;
		_longDouble = src._longDouble;
	}
	return *this;
};

int Converter::indexInTab(std::string str){
	for (int i = 0; i < 8; i++) {
		if (_pseudoLiterals[i] == str)
			return i;
	}
	return -1;
}

void	Converter::printConversions(std::string literal){

	int i = indexInTab(literal);
	
	if (i != -1)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (i % 2 != 0)
		{
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << literal.erase(literal.length() - 1, 1) << std::endl;
		}
		else 
		{
			std::cout << "float: " << literal << "f" << std::endl;
			std::cout << "double: " << literal << std::endl;
		}
		return ;
	}

	// not number
	if (_literal.fail() && literal[literal.length() - 1] == 'f')
	{
		std::cout << "FIRST FAIL!!" << std::endl;
		_literal.clear();
		_literal.flush();
		_literal << literal.erase(literal.length() - 1, 1);
		std::string tmp;
		_literal >> tmp;
		std::cout << tmp << "    " << _literal.fail() << std::endl;
		_literal >> _longDouble;
		std::cout << std::boolalpha << _literal.fail() << " -" << _longDouble << std::endl;
	}
	if (_literal.fail())
	{
		std::cout << "FAIL!!" << std::endl;
		std::cout << "char: ";
		if (literal.length() == 1)
		{
			if (std::isprint(literal[0]))
		    	std::cout << literal[0] << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	// number
	std::cout << "char: ";
	if (_longDouble >= 0 && _longDouble <= 255)
	{
		if (std::isprint(static_cast<char>(_longDouble)))
			std::cout << static_cast<char>(_longDouble);
		else
			std::cout << "Non displayable";
	}
	else { std::cout << "impossible"; }
	std::cout << std::endl;

	std::cout << "int: ";
	if (_longDouble >= INT_MIN && _longDouble <= INT_MAX)
		std::cout << static_cast<int>(_longDouble);
	else { std::cout << "impossible"; }
	std::cout << std::endl;

	std::cout << "float: "	<< std::fixed << std::setprecision(1) << static_cast<float>(_longDouble) << "f" << std::endl;
	std::cout << "double: "	<< std::fixed << std::setprecision(1) << static_cast<float>(_longDouble) << std::endl;
}

Converter::Converter(void){};

std::string	const Converter::_pseudoLiterals[] = {"inf", "inff", "+inf", "+inff",  "-inf", "-inff", "nan", "nanf"};
 