/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:33:21 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/02 15:27:26 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/_types/_size_t.h>
#include "iter.hpp"

template <typename T>
void	addToMaj(T *arg){
	*arg += 'A' - 'a';
}

template <typename T>
void	printTab(T *tab, size_t size){
	for (size_t i = 0; i < size; i++) {
		std::cout << tab[i] << std::endl;
	}
}

int main( void ) {
	
	int	tabInt[10];
	for (size_t i = 0; i < 10; i++){
		tabInt[i] = i + 'a';
	}

	printTab(tabInt, 10);
	std::cout << "iter function called!" << std::endl;
	iter(tabInt, 10, addToMaj);
	printTab(tabInt, 10);
	
	char	tabChar[10];
	for (size_t i = 0; i < 10; i++){
		tabChar[i] = i + 'a';
	}

	printTab(tabChar, 10);
	std::cout << "iter function called!" << std::endl;
	iter(tabChar, 10, addToMaj);
	printTab(tabChar, 10);
	
	return 0;
}