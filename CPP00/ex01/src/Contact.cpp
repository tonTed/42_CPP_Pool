/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:45:47 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 10:50:02 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(){}

Contact::Contact(std::string& firstName, std::string& lastName, std::string& nickname,
	std::string& phoneNumber, std::string& darkestSecret) :
		_firstName(firstName), _lastName(lastName), _nickname(nickname),
		_phoneNumber(phoneNumber), _darkestSecret(darkestSecret){}

Contact::~Contact(){}

std::string	Contact::getFirstName(void) const { return (this->_firstName); }

std::string	Contact::getLastName(void) const { return (this->_lastName); }

std::string	Contact::getNickname(void) const { return (this->_nickname); }

std::string	Contact::getPhoneNumber(void) const { return (this->_phoneNumber); }

std::string	Contact::getDarkestSecret(void) const { return (this->_darkestSecret); }

void	Contact::printContact() const {
	
	std::cout << "First name: " << this->_firstName << std:: endl;
	std::cout << "Last name: " << this->_lastName << std:: endl;
	std::cout << "Nickname: " << this->_nickname << std:: endl;
	std::cout << "Phone number: " << this->_phoneNumber << std:: endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std:: endl;
}
