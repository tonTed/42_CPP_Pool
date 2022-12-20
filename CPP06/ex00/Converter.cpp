/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:30:16 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/20 10:42:25 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(std::string literal) : _char(literal) {
	setFlag();
	if (!_flag)
	{
		std::cout << "Bad input!" << std::endl;
		return;
	}
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
	if (_char.length() == 1)
	{
		if (std::isdigit(_char[0]))
			_flag = T_INT;
		else
			_flag = T_CHAR;
	}
	else {
		_flag = T_INT;

		int i = 0;
		while (_flag && _char[i]){
			if (isdigit(_char[i]))
				;
			else if (i && _char[i] == '.' && _char[i + 1])
			{
				if (_flag &= T_FLOAT | T_DOUBLE)
					_flag = BAD_INPUT;
				else
					_flag = T_DOUBLE;
			}
			else if (i && _char[i] == 'f' && !_char[i + 1] && isdigit(_char[i - 1]))
				_flag = T_FLOAT;
			else
				_flag = BAD_INPUT;
			i++;
		}
	};
}