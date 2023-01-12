/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:30:16 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/12 18:38:17 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
#include <iomanip>

void print_byte_as_bits(char val) {
	for (int i = 7; 0 <= i; i--) {
		printf("%c", (val & (1 << i)) ? '1' : '0');
	}
  std::cout << std::endl;
}

Converter::Converter(std::string literal) : _literal(literal){
	if (!isPseudoLiteral())
		return ;
	// setFlag();
	// if (!_flag)
	// {
	// 	std::cout << "Bad input!" << std::endl;
	// 	return ;
	// }
	// convertAll();
	// printConversions();
};

Converter::Converter(Converter const & src){ *this = src; };

Converter::~Converter(void){};

Converter&	Converter::operator=(Converter const & src){
	if (this != &src){
		_flag = src._flag;
		_char = src._char;
		_int = src._int;
		_float = src._float;
		_double = src._double;
	}

	return (*this);
};

Converter::Converter(void){};

void	Converter::setFlag(void){
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
		if (_literal[0] == '-' && ++i)
			_flag |= NEG;
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
	print_byte_as_bits(_flag);
}

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

void	Converter::convertAll(void){

	char	flag = _flag;
	flag &= ~NEG;

	switch (flag) {
		case T_INT:
			try {
				
				_int = std::stoi(_literal); 
				_float = static_cast<float>(_int);
				_double = static_cast<double>(_int);
				_char = convertToChar();

				_floatOut = std::to_string(_float);
				_doubleOut = std::to_string(_double);
			
			} catch(std::out_of_range)
			{
				_intOut = "impossible"; 
				_charOut = "impossible";
				_floatOut = "impossible";
				_doubleOut = "impossible";
			};
			break;
		case T_FLOAT:
			_float = std::stof(_literal);
			_int = static_cast<int>(_float);
			_double = static_cast<double>(_float);
			_char = convertToChar();
			break;
		case T_DOUBLE:
			_double = std::stod(_literal);
			_int = static_cast<int>(_double);
			_float = static_cast<float>(_double);
			_char = convertToChar();
			break;
		case T_CHAR:
			_char = _literal[0];
			_int = static_cast<int>(_char);
			_float = static_cast<float>(_char);
			_double = static_cast<double>(_char);
			break;
	}
};

char	Converter::convertToChar(void){

	std::string	ret;

	if (_int >= 0 && _int <= 255)
	{
		if (std::isprint(_int))
		{
			_charOut = std::string(1, _int);
			return static_cast<char>(_int);
		}
		else
			_charOut = "Non displayable";
	}
	else
		_charOut = "impossible";
	return 1;
};

void	Converter::printConversions(void){

	std::cout << "char: " << _charOut << std::endl;
	std::cout << "int: " << _intOut << std::endl;
	std::cout << "float: " << _floatOut << std::endl;
	std::cout << "double: " << _doubleOut << std::endl;
};

std::string	const Converter::_pseudoLiterals[] = {"inf", "inff", "+inf", "+inff",  "-inf", "-inff", "nan", "nanf"};