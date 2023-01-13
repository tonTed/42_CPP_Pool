/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:15:28 by tonted            #+#    #+#             */
/*   Updated: 2023/01/13 17:42:03 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstddef>
#include <cstring>
#include <exception>
#include <stdexcept>

Span::Span(void){};

Span::Span(unsigned int n) : _size(n), _tab(new int[n]){ _currentElement = 0; };

Span::Span(Span const & src) : _tab(NULL) { *this = src; }

Span::~Span(void){ delete [] _tab; };

Span &	Span::operator=(const Span &src){
	if (&src != this){
		delete [] _tab;

		_tab =  new int[src._size];
		_size = src._size;

		std::memcpy(this->_tab, src._tab, _size * sizeof(int));
	}

	return *this;
}

void	Span::addNumber(int toAdd){
	if (_currentElement == _size)
		throw std::length_error("Span is already full");
	_tab[_currentElement] = toAdd;
	_currentElement++;

	if (DEBUG) { std::cout << "number: " << toAdd << " added in span." << std::endl; }
}
