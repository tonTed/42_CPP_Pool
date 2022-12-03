/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:39:03 by tonted            #+#    #+#             */
/*   Updated: 2022/12/02 23:12:56 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	this->_i = 0;
	this->_work();
}

PhoneBook::~PhoneBook(){

}

std::string	PhoneBook::_get_input_not_empty(std::string const prefix) const {
	
	std::string	ret;
	
	do{
		std::cout << prefix ; std::getline(std::cin, ret);
		ret.erase(std::remove_if(ret.begin(), ret.end(), ::isspace), ret.end());
	} while (!ret.length());
	return (ret);
}

void	PhoneBook::add_contact(void){
	
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	
	first_name = this->_get_input_not_empty("First Name: ");
	last_name = this->_get_input_not_empty("Last Name: ");
	nickname = this->_get_input_not_empty("Nickname: ");
	phone_number = this->_get_input_not_empty("Phone Number: ");
	darkest_secret = this->_get_input_not_empty("Darkest Secret: ");
	
	this->_contacts[this->_i].set_first_name(first_name);
	this->_contacts[this->_i].set_last_name(last_name);
	this->_contacts[this->_i].set_nickname(nickname);
	this->_contacts[this->_i].set_phone_number(phone_number);
	this->_contacts[this->_i].set_darkest_secret(darkest_secret);
	if (this->_i == 7)
		this->_i = 0;
	else
		this->_i++;
}

void	PhoneBook::_work(void){
	std::string	input;

	do {
		std::getline(std::cin, input);
		if (input == ADD)
			this->add_contact();
		else if (input == SEARCH)
			std::cout << input << std::endl;
		else if (input == EXIT)
			break ;
	} while (input != EXIT);
}