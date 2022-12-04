/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:56:10 by tonted            #+#    #+#             */
/*   Updated: 2022/12/04 15:10:14 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
	std::string	string = "HI THIS IS BRAIN";

	std::string	*stringPTR = &string;
	
	std::string	&stringREF = string;

	printf("string    address: %p\n", &string);
	printf("stringPTR address: %p\n", stringPTR);
	printf("stringREF address: %p\n", stringREF.c_str());

	std::cout << std::endl;

	std::cout << "string    value: " + string << std::endl;
	std::cout << "stringPTR value: " + *stringPTR << std::endl;
	std::cout << "stringREF value: " + stringREF << std::endl;

	return 0;
}
