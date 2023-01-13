/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:33:21 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/13 17:40:04 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main( void ) {

	Span a(5);

	a.addNumber(42);
	a.addNumber(12);
	a.addNumber(-4);
	a.addNumber(51);
	a.addNumber(123);
	a.addNumber(1);
}