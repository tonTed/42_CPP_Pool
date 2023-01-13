/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:33:21 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/13 00:52:13 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <list>

int main( void ) {

	std::list<int> l1;

	l1.push_back(1);
	l1.push_back(5);
	
	easyfind(l1, 5);
	easyfind(l1, 2);
}