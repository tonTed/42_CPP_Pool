/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:56:43 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 13:21:55 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
#define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
#define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define ERROR "This is unacceptable ! I want to speak to the manager now."

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug( void ){ std::cout << DEBUG << std::endl; }

void Harl::info( void ){ std::cout << INFO << std::endl; }

void Harl::warning( void ){ std::cout << WARNING << std::endl; }

void Harl::error( void ){ std::cout << ERROR << std::endl; }

void Harl::complain( std::string level ){
		
	for (size_t i = 0; i < this->_levels->length(); i++){
		if (level == this->_levels[i])
			(this->*f_levels[i])();
	}
}

std::string	Harl::_levels[] = {"INFO", "DEBUG", "WARNING", "ERROR"};
Harl::ptrf	Harl::f_levels[] = {&Harl::info, &Harl::debug, &Harl::warning, &Harl::error};