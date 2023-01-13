/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:30:16 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/12 20:16:08 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <cctype>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <ostream>

void print_byte_as_bits(char val) {
	for (int i = 7; 0 <= i; i--) {
		printf("%c", (val & (1 << i)) ? '1' : '0');
	}
  std::cout << std::endl;
}

void	Converter::printImpossible(void){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
};

bool	Converter::isPseudoLiteral(void){
	
	int i = -1;
	for (int _i = 0; _i < 8; _i++) 
	{
		if (_pseudoLiterals[_i] == _literal)
		{
			i = _i;
			break;
		}
	}
	
	if (i != -1)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (i % 2 != 0)
		{
			std::cout << "float: " << _literal << std::endl;
			std::cout << "double: " << _literal.erase(_literal.length() - 1, 1) << std::endl;
		}
		else 
		{
			std::cout << "float: " << _literal << "f" << std::endl;
			std::cout << "double: " << _literal << std::endl;
		}
		return false;
	}
	return true;
};

bool	Converter::setFlag(void){
	if (_literal.length() == 1)
	{
		if (std::isdigit(_literal[0]))
			_flag = T_INT;
		else
			_flag = T_CHAR;
	}
	else {
		_flag = T_INT;

		int i = 0;
		if (_literal[0] == '-')
			i++;
		while (_flag && _literal[i]){
			if (isdigit(_literal[i]))
				;
			else if (i && _literal[i] == '.' && _literal[i + 1])
			{
				if (_flag &= T_FLOAT | T_DOUBLE)
					_flag = BAD_INPUT;
				else
					_flag = T_DOUBLE;
			}
			else if (i && _literal[i] == 'f' && !_literal[i + 1] && isdigit(_literal[i - 1]))
				_flag = T_FLOAT;
			else
				_flag = BAD_INPUT;
			i++;
		}
	};
	if (_flag)
		return true;
	printImpossible();
	return false;
}

Converter::Converter(std::string literal) : _literal(literal){
	if (!isPseudoLiteral() || !setFlag())
		return ;
	convertAll();
};

Converter::Converter(Converter const & src) : _literal(src._literal), _flag(src._flag){};

Converter::~Converter(void){};

Converter&	Converter::operator=(Converter const & src){
	if (this != &src){
		this->_literal = src._literal;
		this->_flag = src._flag;
	}

	return (*this);
};

Converter::Converter(void){};

void	Converter::fromDouble(){
	double	double_;

	try {
		double_ = std::stod(_literal);
	} catch(std::out_of_range){	printImpossible(); return; };

	std::cout << "char: ";
	if (double_ < std::numeric_limits<char>::min() || double_ > std::numeric_limits<char>::max()){ std::cout << "impossible" << std::endl; }
	else { std::isprint(double_) ? std::cout << static_cast<char>(double_) : std::cout << "Non Displayable"; std::cout << std::endl; }

	std::cout << "int: "; 
	if (double_ < std::numeric_limits<int>::min() || double_ > std::numeric_limits<int>::max()){ std::cout << "impossible"; }
	else { std::cout << static_cast<int>(double_); }
	std::cout << std::endl;

	std::cout << "float: ";
	if (double_ < std::numeric_limits<float>::min()){ std::cout << "-inff"; }
	else if (double_ > std::numeric_limits<float>::max()){ std::cout << "inff"; }
	else { std::cout << std::fixed << std::setprecision(1) << static_cast<float>(double_) << "f"; }
	std::cout << std::endl;

	std::cout << "double: "	<< std::fixed << std::setprecision(1) << double_ << std::endl;
}

void	Converter::fromFloat(){
	float	float_;

	try {
		float_ = std::stof(_literal);
	} catch(std::out_of_range){	printImpossible(); return; };

	std::cout << "char: ";
	if (float_ < std::numeric_limits<char>::min() || float_ > std::numeric_limits<char>::max()){ std::cout << "impossible" << std::endl; }
	else { std::isprint(float_) ? std::cout << static_cast<char>(float_) : std::cout << "Non Displayable"; std::cout << std::endl; }

	std::cout << "int: "; 
	if (float_ < std::numeric_limits<int>::min() || float_ > std::numeric_limits<int>::max()){ std::cout << "impossible"; }
	else { std::cout << static_cast<int>(float_); }
	std::cout << std::endl;

	std::cout << "float: "	<< std::fixed << std::setprecision(1) << float_ << "f" << std::endl;
	std::cout << "double: "	<< std::fixed << std::setprecision(1) << static_cast<double>(float_) << std::endl;
}

void	Converter::fromInt(){
	int	int_;

	try {
		int_ = std::stoi(_literal);
	} catch(std::out_of_range){	printImpossible(); return; };

	std::cout << "char: ";
	if (int_ < std::numeric_limits<char>::min() || int_ > std::numeric_limits<char>::max())
	{
		std::cout << "impossible" << std::endl;
	}
	else 
	{
		std::isprint(int_) ? std::cout << static_cast<char>(int_) : std::cout << "Non Displayable"; std::cout << std::endl; 
	}
	std::cout << "int: "	<< static_cast<int>(int_) << std::endl;
	std::cout << "float: "	<< std::fixed << std::setprecision(1) << static_cast<float>(int_) << "f" << std::endl;
	std::cout << "double: "	<< std::fixed << std::setprecision(1) << static_cast<double>(int_) << std::endl;
}

void	Converter::fromChar(){
	char	char_;

	char_ = _literal[0];
	if (char_ < std::numeric_limits<char>::min() || char_ > std::numeric_limits<char>::max())
	{
		printImpossible();
		return;
	}
	std::cout << "char: ";	std::isprint(char_) ? std::cout << char_ : std::cout << "Non Displayable"; std::cout << std::endl; 
	std::cout << "int: "	<< static_cast<int>(char_) << std::endl;
	std::cout << "float: "	<< std::fixed << std::setprecision(1) << static_cast<float>(char_) << "f" << std::endl;
	std::cout << "double: "	<< std::fixed << std::setprecision(1) << static_cast<double>(char_) << std::endl;
}

void	Converter::convertAll(void){

	char	flag = _flag;

	switch (flag) {
		case T_INT:
			fromInt();
			break;
		case T_FLOAT:
			fromFloat();
			break;
		case T_DOUBLE:
			fromDouble();
			break;
		case T_CHAR:
			fromChar();
			break;
	}
};

std::string	const Converter::_pseudoLiterals[] = {"inf", "inff", "+inf", "+inff",  "-inf", "-inff", "nan", "nanf"};