/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:35:59 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/04 10:59:08 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define DEBUG 1

template <typename T>
class Array {

public:
	Array(void) : _array(new T[0]), _size(0){ 
		if(DEBUG) std::cout << "Default constructor." << std::endl;
	};
	Array(unsigned int n) : _array(new T[n]), _size(n){
		if(DEBUG) std::cout << "Array constructeur with size " << n << "." << std::endl;
	};
	~Array(void){ delete [] _array; 
		if(DEBUG) std::cout << "Default destructor." << std::endl; 
	};

	Array<T> & operator=(Array<T> const & src){
		
		if(DEBUG) std::cout << "Construction by copying." << std::endl;
		(void)src;
		// Array<T> ret = new T[src._size];

		// ret->_size = src._size;
		
		// for (size_t i = 0; i < _size; i++) {
		// 	ret->_array[i] = src._array[i];
		// }

		// return *ret;
		return *this;
	}
	
	T		*_array;

private:
	size_t	_size;
};