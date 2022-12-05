/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:26:38 by tonted            #+#    #+#             */
/*   Updated: 2022/12/05 14:04:42 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime> 
#include <iostream>
#include <cstdio>

Account::Account( int initial_deposit ) : _amount(initial_deposit){
	this->_displayTimestamp();
	this->_accountIndex = this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" <<  this->_amount 
				<< ";created" << std::endl;
}

Account::~Account( void ){
	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" <<  this->_amount 
				<< ";closed" << std::endl;
}

int		Account::getNbAccounts( void ){
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}

int		Account::getNbDeposits( void ){
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals( void ){
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << Account::getNbAccounts()
				<< ";total:" << Account::getTotalAmount()
				<< ";deposits:" << Account::getNbDeposits()
				<< ";withdrawals:" << Account::getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit( int deposit ){
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" <<  this->_amount 
				<< ";deposit:" <<  deposit 
				<< ";amount:" <<  this->_amount + deposit
				<< ";nb_deposits:" << ++this->_nbDeposits
				<< std::endl;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout	<< "index:" << this->_accountIndex
					<< ";p_amount:" <<  this->_amount 
					<< ";withdrawal:refused" << std::endl;
		return (false);	
	}
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount 
				<< ";withdrawal:" << withdrawal 
				<< ";amount:" << this->_amount - withdrawal
				<< ";nb_withdrawals:" << ++this->_nbWithdrawals
				<< std::endl;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	return (true);
}

int		Account::checkAmount( void ) const{
	return (this->_amount);
}

void	Account::displayStatus( void ) const{
	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount 
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" <<  this->_nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp( void ){
	time_t time = ::time(NULL);

	struct tm * time_info;
	time_info = ::localtime(&time);

	char	s_time[20];
	::strftime(s_time, 20, "[%G%m%d_%H%M%S] ", time_info);

	std::cout << s_time;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
