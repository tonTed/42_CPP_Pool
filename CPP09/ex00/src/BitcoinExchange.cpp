//
// Created by Teddy BLANCO on 2023-04-20.
//

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(const std::string & inputFile) {	Log::logFunction(__FUNCTION__);
	_dayByMonthUpdate();
	_updateDB();
	_manageInput(inputFile);
}

BitcoinExchange::~BitcoinExchange() {	Log::logFunction(__FUNCTION__);}

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
//	Log::logMap(_db);
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
		throw std::invalid_argument("bad input => " + date);
	}

	//check if date is valid
	if (year < START_YEAR || month < 1 || month > 12 || day < 1 || day > _dayByMonth[month]) {
		throw std::invalid_argument("bad input => " + date);
	}

	//convert date to timestamp
	size_t timestamp = 0;

	timestamp += (year - START_YEAR) * DAY_BY_YEAR;
	for (size_t i = 1; i < month; i++) {
		timestamp += _dayByMonth[i];
	}
	timestamp += day - 1;

	return timestamp;
}

std::string	BitcoinExchange::_convertTimestampToDate(size_t timestamp) {	Log::logFunction(__FUNCTION__);

	std::string date;

	size_t year = timestamp / DAY_BY_YEAR + START_YEAR;
	size_t month = 1;
	size_t day = 1;

	timestamp -= (year - START_YEAR) * DAY_BY_YEAR;
	while (timestamp > _dayByMonth[month]) {
		timestamp -= _dayByMonth[month];
		month++;
	}
	day += timestamp;

	date += std::to_string(year) + "-";
	if (month < 10)
		date += "0";
	date += std::to_string(month) + "-";
	if (day < 10)
		date += "0";
	date += std::to_string(day);

	return date;
}

void	BitcoinExchange::_manageInput(const std::string &inputFile) {	Log::logFunction(__FUNCTION__);

	std::ifstream file(inputFile);

	std::string line;

	std::string error = "Error: ";

	if (file.is_open()) {
		Log::logToConsole("File opened");
		//skip first line

		std::getline(file, line);
		while(std::getline(file, line))
		{
			try
			{
				std::string date = line.substr(0, line.find('|'));
				date.erase(remove_if(date.begin(), date.end(), isspace), date.end());

				std::string value = line.substr(line.find('|') + 1);
				value.erase(remove_if(value.begin(), value.end(), isspace), value.end());

				size_t timestamp = _convertDateToTimestamp(date);
				size_t closetTimestamp = _getClosestTimestamp(timestamp);
				float amount = std::stof(value);

				if (amount < 0)
				{
					throw std::invalid_argument("not a positive number.");
				}
				if (amount > 1000)
				{
					throw std::invalid_argument("too large a number.");
				}

				std::cout << YELLOW << _convertTimestampToDate(timestamp) << " => " << amount << " = " << amount * _db[closetTimestamp] << RESET << std::endl;
			}
			catch (std::out_of_range & e)
			{
				std::cout << RED << error + "bad input => " + line << RESET << std::endl;
			}
			catch (std::exception & e)
			{
				std::cout << MAGENTA << error + e.what() << RESET << std::endl;
			}
		}
	}
	else
	{
		Log::logToConsole("File not opened");
		exit(1);
	}
//	Log::logMap(_db);
}

size_t	BitcoinExchange::_getClosestTimestamp(size_t timestamp) {	Log::logFunction(__FUNCTION__);

	size_t closestTimestamp = 0;

	if (_db.find(timestamp) != _db.end()) {
		closestTimestamp = timestamp;
	}
	else {
		for (std::map<size_t, float>::iterator it = _db.begin(); it != _db.end(); it++)
		{
			if (it->first < timestamp) {
				closestTimestamp = it->first;
			}
			else if (it->first > timestamp) {
				break;
			}
		}
	}

	return closestTimestamp;
}