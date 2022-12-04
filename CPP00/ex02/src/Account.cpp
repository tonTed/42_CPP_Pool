/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:26:38 by tonted            #+#    #+#             */
/*   Updated: 2022/12/03 21:55:47 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime> 
#include <iostream>

Account::Account( int initial_deposit ){
	this->_displayTimestamp();
	this->_amount = initial_deposit;
}

Account::~Account( void ){
	this->_displayTimestamp();
}

int		Account::getNbAccounts( void ){
	return (0);
}

int		Account::getTotalAmount( void ){
	return (0);
}

int		Account::getNbDeposits( void ){
	return (0);
}

int		Account::getNbWithdrawals( void ){
	return (0);
}

void	Account::displayAccountsInfos( void ){

}

void	Account::makeDeposit( int deposit ){
	this->_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
	this->_amount -= withdrawal;
	return (0);
}

int		Account::checkAmount( void ) const{
	return (0);
}

void	Account::displayStatus( void ) const{

}

void	Account::_displayTimestamp( void ){
	time_t time = ::time(NULL);

	struct tm * time_info;
	time_info = ::localtime(&time);

	char	s_time[20];
	::strftime(s_time, 20, "[%G%m%d_%H%M%S] ", time_info);

	std::cout << s_time << std::endl;
}


