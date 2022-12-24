/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:39:03 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 11:07:19 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <_ctype.h>
#include <algorithm>

PhoneBook::PhoneBook() : _i(0){ this->_work(); }

PhoneBook::~PhoneBook(){}

std::string	PhoneBook::_getInputNotEmpty(std::string const prefix) const {
	
	std::string	ret;
	
	do{
		std::cout << prefix ; std::getline(std::cin, ret);
		ret.erase(std::remove_if(ret.begin(), ret.end(), ::isspace), ret.end());
	} while (!ret.length());
	return (ret);
}

void	PhoneBook::_addContact(void){
	
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
	
	firstName = this->_getInputNotEmpty("First Name: ");
	lastName = this->_getInputNotEmpty("Last Name: ");
	nickname = this->_getInputNotEmpty("Nickname: ");
	phoneNumber = this->_getInputNotEmpty("Phone Number: ");
	darkestSecret = this->_getInputNotEmpty("Darkest Secret: ");
	
	_contacts[_i] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	
	if (this->_i == 7)
		this->_i = 0;
	else
		this->_i++;
}

bool	PhoneBook::_inputSearchValid(std::string const input) const {
	if (input.length() != 1 || !::isdigit(input[0]))
		return (false);

	long i = std::stoul(input);
	if (i >= std::end(this->_contacts) - std::begin(this->_contacts))
		return (false);
	if (!(this->_contacts[i].getFirstName().length()))
		return (false);
	return (true);
}

void	PhoneBook::_searchContact(void) const {
	
	std::string	input;

	do {
		std::cout << "Select index for détails: ";
		std::getline(std::cin, input);
	} while (!this->_inputSearchValid(input));

	this->_contacts[std::stoul(input)].printContact();
}

void	PhoneBook::_printHeader(void) const {
	
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "index" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "first_name" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "last_name" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "nickname" << std::endl;
}

void	PhoneBook::_printCell(std::string s) const {

	std::string	tmp;

	if (s.length() > 10)
	{
		tmp = s.substr(0, 10);
		tmp.replace(9, 1, 1, '.');
	}
	else
		tmp = s;
	std::cout << std::setfill(' ') << std::setw(10) << tmp;
}

void	PhoneBook::_printLine(size_t i) const {

	std::string	tmp;
	
	if (!this->_contacts[i].getFirstName().length())
		return ;
	this->_printCell(std::to_string(i));
	std::cout << "|";
	this->_printCell(this->_contacts[i].getFirstName());
	std::cout << "|";
	this->_printCell(this->_contacts[i].getLastName());
	std::cout << "|";
	this->_printCell(this->_contacts[i].getNickname());
	std::cout << std::endl;
	
}

void	PhoneBook::_printPhoneBook(void) const {

	this->_printHeader();
	
	size_t	len_tab = std::end(this->_contacts) - std::begin(this->_contacts);
	for (size_t i = 0; i < len_tab; i++)
		this->_printLine(i);
}

void	PhoneBook::_work(void){
	std::string	input;

	do {
		std::cout << "Choose an option(ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (input == ADD)
			this->_addContact();
		else if (input == SEARCH){
			if (!this->_contacts[0].getFirstName().length()){
				std::cout << "List is empty." << std::endl;
				continue;
			}
			this->_printPhoneBook();
			this->_searchContact();
		}
		else if (input == EXIT)
			break ;
	} while (input != EXIT);
}