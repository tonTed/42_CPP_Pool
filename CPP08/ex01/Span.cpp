/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:15:28 by tonted            #+#    #+#             */
/*   Updated: 2023/01/13 19:10:05 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstddef>
#include <cstring>
#include <exception>
#include <stdexcept>
#include <string>

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

	if (!_currentElement) { _min = toAdd; _max = toAdd; }
	if (toAdd < _min) { _min = toAdd; }
	if (toAdd > _max) { _max = toAdd; }

	_currentElement++;

	if (DEBUG) { std::cout << "number: " << toAdd << " added in span." << std::endl; }
}

void	Span::addNumber(int toAdd, unsigned int amount){
	if (_size - _currentElement < amount)
		throw std::out_of_range("Can't be add " + std::to_string(amount) + " elements in Span.");
	for (unsigned int i = 0; i < amount; i++) {
		addNumber(toAdd);
	}
}

int	Span::shortestSpan(void){
	if (_currentElement < 2)
		throw std::logic_error("not enough elements to calculate a distance.");
	
	int	ret;
	int	tmp;

	_tab[0] > _tab[1] ? ret = _tab[0] - _tab[1] : ret = _tab[1] - _tab[0];

	for (unsigned int i = 0; i < _currentElement; i++) {
		for (unsigned int j = i + 1; j < _currentElement; j++) {
			_tab[i] > _tab[j] ? tmp = _tab[i] - _tab[j] : tmp = _tab[j] - _tab[i];
			!(tmp < ret) ?: ret = tmp;
		}
	}
	return ret;
};

int	Span::longestSpan(void){
	if (_currentElement < 2)
		throw std::logic_error("not enough elements to calculate a distance.");
	return (_max - _min);
};
