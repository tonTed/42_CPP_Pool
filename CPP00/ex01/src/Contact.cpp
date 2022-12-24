/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:45:47 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 10:40:44 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

std::string	Contact::getFirstName(void) const { return (this->_first_name); }

std::string	Contact::getLastName(void) const { return (this->_last_name); }

std::string	Contact::getNickname(void) const { return (this->_nickname); }

std::string	Contact::getPhoneNumber(void) const { return (this->_phone_number); }

std::string	Contact::getDarkestSecret(void) const { return (this->_darkest_secret); }

void	Contact::setFirstName(std::string first_name){ this->_first_name = first_name; }

void	Contact::setLastName(std::string last_name){ this->_last_name = last_name; }

void	Contact::setNickname(std::string nickname){ this->_nickname = nickname; }

void	Contact::setPhoneNumber(std::string phone_number){ this->_phone_number = phone_number; }

void	Contact::setDarkestSecret(std::string darkest_secret){ this->_darkest_secret = darkest_secret; }

void	Contact::printContact() const {
	
	std::cout << "First name: " << this->_first_name << std:: endl;
	std::cout << "Last name: " << this->_last_name << std:: endl;
	std::cout << "Nickname: " << this->_nickname << std:: endl;
	std::cout << "Phone number: " << this->_phone_number << std:: endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std:: endl;
}
