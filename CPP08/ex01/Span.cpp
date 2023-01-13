/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:15:28 by tonted            #+#    #+#             */
/*   Updated: 2023/01/13 01:26:23 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstddef>
#include <cstring>

Span::Span(void){};

Span::Span(unsigned int n) : _size(n), _tab(new int[n]){};

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
