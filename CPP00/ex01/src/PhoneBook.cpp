/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:39:03 by tonted            #+#    #+#             */
/*   Updated: 2022/12/03 20:13:38 by tonted           ###   ########.fr       */
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

void	PhoneBook::_add_contact(void){
	
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

bool	PhoneBook::_input_search_valid(std::string const input) const {
	if (!input.length())
		return (false);
	if (!((size_t)std::count_if(std::begin(input), std::end(input), ::isdigit) == input.length()))
		return (false);

	long i = std::stoul(input);
	if (i >= std::end(this->_contacts) - std::begin(this->_contacts))
		return (false);
	if (!(this->_contacts[i].get_first_name().length()))
		return (false);
	return (true);
}

void	PhoneBook::_search_contact(void) const {
	
	std::string	input;

	do {
		std::cout << "Select index for détails: ";
		std::getline(std::cin, input);
	} while (!this->_input_search_valid(input));

	this->_contacts[std::stoul(input)].print_contact();
}

void	PhoneBook::_print_header(void) const {
	
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "index" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "first_name" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "last_name" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "nickname" << std::endl;
}

void	PhoneBook::_print_cell(std::string s) const {

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

void	PhoneBook::_print_line(size_t i) const {

	std::string	tmp;
	
	if (!this->_contacts[i].get_first_name().length())
		return ;
	this->_print_cell(std::to_string(i));
	std::cout << "|";
	this->_print_cell(this->_contacts[i].get_first_name());
	std::cout << "|";
	this->_print_cell(this->_contacts[i].get_last_name());
	std::cout << "|";
	this->_print_cell(this->_contacts[i].get_nickname());
	std::cout << std::endl;
	
}

void	PhoneBook::_print_phone_book(void) const {

	this->_print_header();
	
	size_t	len_tab = std::end(this->_contacts) - std::begin(this->_contacts);
	for (size_t i = 0; i < len_tab; i++)
		this->_print_line(i);
}

void	PhoneBook::_work(void){
	std::string	input;

	do {
		std::cout << "Choose an option(ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (input == ADD)
			this->_add_contact();
		else if (input == SEARCH){
			if (!this->_contacts[0].get_first_name().length()){
				std::cout << "List is empty." << std::endl;
				continue;
			}
			this->_print_phone_book();
			this->_search_contact();
		}
		else if (input == EXIT)
			break ;
	} while (input != EXIT);
}