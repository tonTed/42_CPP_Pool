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

	std::string line;

	if (file.is_open()) {
		Log::logToConsole("File opened");
		while(std::getline(file, line)) {
			std::string date = line.substr(0, line.find(','));
			std::string value = line.substr(line.find(',') + 1);

			try {
				size_t timestamp = _convertDateToTimestamp(date);
				float price = std::stof(value);
				_db[timestamp] = price;
			}
			catch (std::exception & e) {
				Log::logToConsole("Error while parsing line: " + line + ".");
			}
		}
	}
	else {
		Log::logToConsole("File not opened");
		exit(1);
	}
	Log::logMap(_db);
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

size_t	BitcoinExchange::_convertDateToTimestamp(std::string const & date) {	Log::logFunction(__FUNCTION__);

	size_t year;
	size_t month;
	size_t day;

	//split date
	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	}
	catch (std::exception & e) {
		Log::logToConsole("Date is not valid");
		throw std::invalid_argument("Date is not valid");
	}

	//check if date is valid
	if (year < START_YEAR || month < 1 || month > 12 || day < 1 || day > _dayByMonth[month]) {
		Log::logToConsole("Date is not valid");
		throw std::invalid_argument("Date is not valid");
	}

	//convert date to timestamp
	size_t timestamp = 0;

	timestamp += (year - START_YEAR) * DAY_BY_YEAR;
	for (size_t i = 1; i < month; i++) {
		timestamp += _dayByMonth[i];
	}
	timestamp += day;

	return timestamp;
}


