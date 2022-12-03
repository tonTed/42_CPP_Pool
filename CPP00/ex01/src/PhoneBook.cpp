/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:39:03 by tonted            #+#    #+#             */
/*   Updated: 2022/12/02 20:34:53 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	this->_work();
	this->_i = 0;
}

PhoneBook::~PhoneBook(){

}

void	PhoneBook::add_contact(void){
	
	std::string	input;
	
	std::cout << "First Name: "; std::getline(std::cin, input);
	this->_contacts[this->_i].set_first_name(input);
	std::cout << "Last Name: "; std::getline(std::cin, input);
	this->_contacts[this->_i].set_last_name(input);
	std::cout << "Nickname: "; std::getline(std::cin, input);
	this->_contacts[this->_i].set_nickname(input);
	std::cout << "Phone Number: ";std::getline(std::cin, input);
	this->_contacts[this->_i].set_phone_number(input);
	std::cout << "Darkest Secret: "; std::getline(std::cin, input);
	this->_contacts[this->_i].set_darkest_secret(input);
	if (this->_i == 7)
		this->_i = 0;
	else
		this->_i++;
}

void	PhoneBook::_work(void){
	std::string	input;

	while (42)
	{
		std::getline(std::cin, input);
		if (input == ADD)
			this->add_contact();
		else if (input == SEARCH)
			std::cout << input << std::endl;
		else if (input == EXIT)
			break ;
		else
			std::cout << "command not exists" << std::endl;
		// break;
	}
}