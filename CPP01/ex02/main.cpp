/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:56:10 by tonted            #+#    #+#             */
/*   Updated: 2022/12/05 14:13:28 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
	std::string	string = "HI THIS IS BRAIN";

	std::string	*stringPTR = &string;
	
	std::string	&stringREF = string;


	std::cout << "string    address: " << &string << std::endl;
	std::cout << "stringPTR address: " << stringPTR << std::endl;
	std::cout << "stringREF address: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "string    value: " << string << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;

	return 0;
}
