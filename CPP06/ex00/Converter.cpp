/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:30:16 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/11 09:30:29 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
#include <iomanip>

Converter::Converter(std::string literal) : _literal(literal){};

Converter::Converter(Converter const & src){ *this = src; };

Converter::~Converter(void){};

Converter&	Converter::operator=(Converter const & src){ return *this;};

Converter::Converter(void){};
 