/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:56:43 by tonted            #+#    #+#             */
/*   Updated: 2022/12/05 11:52:38 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
#define INFO "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
#define WARNING "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month."
#define ERROR "This is unacceptable ! I want to speak to the manager now."

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug( void ){ std::cout << DEBUG << std::endl; }

void Harl::info( void ){ std::cout << INFO << std::endl; }

void Harl::warning( void ){ std::cout << WARNING << std::endl; }

void Harl::error( void ){ std::cout << ERROR << std::endl; }

void Harl::complainSwitch( std::string level ){
	
	size_t	level_num = -1;
	for (size_t i = 0; i < this->_levels->length(); i++)
		if (level == this->_levels[i])
				level_num = i;
	
	switch (level_num)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			this->debug();
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			this->info();
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			this->warning();
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			this->error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void Harl::complain( std::string level ){
	
	void (Harl::*_f_levels[4])(void) = { &Harl::info, &Harl::debug, &Harl::warning, &Harl::error };
	
	size_t	len_levels = this->_levels->length();
	for (size_t i = 0; i < len_levels; i++){
		if (level == this->_levels[i]){
			while (i < len_levels){
				std::cout << "[ " + this->_levels[i] + " ]" << std::endl;
				(this->*_f_levels[i])();
				i++;
				std::cout << std::endl;
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

std::string	Harl::_levels[] = {"INFO", "DEBUG", "WARNING", "ERROR"};