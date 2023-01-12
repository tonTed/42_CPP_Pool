/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:26:41 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/11 14:48:28 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <climits>

class Converter {

public:
	Converter(std::string literal);
	Converter(Converter const & src);
	~Converter(void);

	Converter&	operator=(Converter const & src);

	void	printConversions(std::string literal);

private:
	Converter(void);

	std::stringstream	_literal;
	long double			_longDouble;

	static	std::string const	_pseudoLiterals[8];
	int	indexInTab(std::string str);

};

std::ostream &	operator<<(std::ostream & o, Converter const i);