/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:35:59 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/12 21:35:49 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <cstring>
#include <iostream>
#include <sys/_types/_size_t.h>

#define DEBUG 1

template <typename T>
class Array {

public:
	Array(void) : _array(new T[0]), _size(0){ if(DEBUG) std::cout << "Default constructor." << std::endl; };
	
	Array(unsigned int n) : _array(new T[n]), _size(n){ if(DEBUG) std::cout << "Array constructeur with size " << n << "." << std::endl; };
	
	~Array(void){ if(DEBUG) std::cout << "Default destructor (" << this << " / array: " << _array << ")." << std::endl;
		delete [] _array; 
	};

	Array(Array const & src) : _array(new T(src._size)){ if(DEBUG) std::cout << "Construction by copying." << std::endl;
		*this = src;
	}

	const Array & operator=(Array const & src){ if(DEBUG) std::cout << "Construction by overload." << std::endl;

		this->_size = src._size;

		delete[] _array;
		_array = new T[src._size];
		for (size_t i = 0; i < _size; i++){ this->_array[i] = src._array[i]; }

		return *this;
	}
	
	T		*_array;

private:
	size_t	_size;
};