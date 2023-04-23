//
// Created by Teddy BLANCO on 2023-04-20.
//

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {	Log::logFunction(__FUNCTION__);
	_dayByMonthUpdate();
	_updateDB();
}

BitcoinExchange::~BitcoinExchange() {	Log::logFunction(__FUNCTION__);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {	Log::logFunction(__FUNCTION__);
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {	Log::logFunction(__FUNCTION__);
	if (this != &rhs) {
		//do stuff
	}
	return *this;
}

void	BitcoinExchange::_updateDB() {	Log::logFunction(__FUNCTION__);

	std::ifstream file(DB_FILE);

	if (file.is_open()) {
		Log::logToConsole("File opened");
	}
	else {
		Log::logToConsole("File not opened");

	}
}

void	BitcoinExchange::_dayByMonthUpdate() {	Log::logFunction(__FUNCTION__);

	_dayByMonth[1] = 31;
	_dayByMonth[2] = 28;
	_dayByMonth[3] = 31;
	_dayByMonth[4] = 30;
	_dayByMonth[5] = 31;
	_dayByMonth[6] = 30;
	_dayByMonth[7] = 31;
	_dayByMonth[8] = 31;
	_dayByMonth[9] = 30;
	_dayByMonth[10] = 31;
	_dayByMonth[11] = 30;
	_dayByMonth[12] = 31;

	Log::logMap(_dayByMonth);
}


