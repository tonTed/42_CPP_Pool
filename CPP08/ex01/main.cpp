/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:33:21 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/13 19:03:30 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Span.hpp"

int main( void ) {

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try { sp.addNumber(42); }
	catch (std::exception &e) { std::cout << "execption catch: " << e.what() << std::endl; e.what(); }

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	Span sp2 = Span(10000);
	sp2.addNumber(-14);

	try { std::cout << sp2.longestSpan() << std::endl; }
	catch (std::exception &e) { std::cout << "execption catch: " << e.what() << std::endl; e.what(); }

	for (size_t i = 0; i < 9999; i++) {
		sp2.addNumber(i * 2);
	}
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;


	Span sp3(500);
	sp3.addNumber(42, 250);
	sp3.addNumber(21, 240);
	try { sp3.addNumber(21, 11); }
	catch (std::exception &e) { std::cout << "execption catch: " << e.what() << std::endl; e.what(); }
	sp3.addNumber(-42, 10);
	
}