//
// Created by Teddy BLANCO on 2023-04-20.
//

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {	Log::logFunction(__FUNCTION__);
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



