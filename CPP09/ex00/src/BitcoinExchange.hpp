//
// Created by Teddy BLANCO on 2023-04-20.
//

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>

#include "../../Log.hpp"

#define DB_FILE "db/data.csv"
#define START_YEAR 2000


class BitcoinExchange {

public:

	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & src);
	BitcoinExchange & operator=(BitcoinExchange const & rhs);

private:

	void	_updateDB();

	void	_dayByMonthUpdate();

	std::map<size_t, float>	_db;

	std::map<size_t, size_t>	_dayByMonth;
};


#endif //BITCOINEXCHANGE_HPP
