/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:39:03 by tonted            #+#    #+#             */
/*   Updated: 2022/12/02 14:27:30 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	this->_work();
}

PhoneBook::~PhoneBook(){

}

void	PhoneBook::_work(void){
	std::string	input;

	while (42)
	{
		std::cin >> input;
		if (input == ADD)
			std::cout << input << std::endl;
		else if (input == SEARCH)
			std::cout << input << std::endl;
		else if (input == EXIT)
			break ;
		else
			std::cout << "command not exists" << std::endl;
	}
}