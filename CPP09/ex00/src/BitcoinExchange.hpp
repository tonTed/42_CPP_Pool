//
// Created by Teddy BLANCO on 2023-04-20.
//

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

#include "../../Log.hpp"

class BitcoinExchange {

public:

	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & src);
	BitcoinExchange & operator=(BitcoinExchange const & rhs);

private:

	static std::map<size_t, size_t>	_dayByMonth;
};


#endif //BITCOINEXCHANGE_HPP
