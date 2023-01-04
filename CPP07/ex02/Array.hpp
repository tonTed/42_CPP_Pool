/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:35:59 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/04 09:55:35 by tonted           ###   ########.fr       */
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
	
	T		*_array;

private:
	size_t	_size;
};