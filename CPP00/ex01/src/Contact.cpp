/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:45:47 by tonted            #+#    #+#             */
/*   Updated: 2022/12/02 19:22:42 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::set_first_name(std::string first_name){
	this->_first_name = first_name;
}

void	Contact::set_last_name(std::string last_name){
	this->_last_name = last_name;
}

void	Contact::set_nickname(std::string nickname){
	this->_nickname = nickname;
}

void	Contact::set_phone_number(std::string phone_number){
	this->_phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string darkest_secret){
	this->_darkest_secret = darkest_secret;
}