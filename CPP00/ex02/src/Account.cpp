/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:26:38 by tonted            #+#    #+#             */
/*   Updated: 2022/12/04 11:30:35 by tonted           ###   ########.fr       */
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
	printf("index:%d;amount:%d;created\n", this->_accountIndex, this->_amount);
}

Account::~Account( void ){
	this->_displayTimestamp();
	printf("index:%d;amount:%d;closed\n", this->_accountIndex, this->_amount);
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
	printf("accounts:%d;total:%d;deposits:%d;withdrawals:%d\n",
		Account::getNbAccounts(), Account::getTotalAmount(),
		Account::getNbDeposits(), Account::getNbWithdrawals());
}

void	Account::makeDeposit( int deposit ){
	Account::_displayTimestamp();
	printf("index:%d;p_amount:%d;deposit:%d;amount:%d;nb_deposits:%d\n",
	this->_accountIndex, this->_amount, deposit, this->_amount + deposit, ++this->_nbDeposits);
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		printf("index:%d;p_amount:%d;withdrawal:refused\n", this->_accountIndex, this->_amount);
		return (false);	
	}
	printf("index:%d;p_amount:%d;withdrawal:%d;amount:%d;nb_withdrawals:%d\n",
	this->_accountIndex, this->_amount, withdrawal, this->_amount - withdrawal, ++this->_nbWithdrawals);
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
	printf("index:%d;amount:%d;deposits:%d;withdrawals:%d\n",
		this->_accountIndex, this->_amount, this->_nbDeposits, this->_nbWithdrawals);
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
