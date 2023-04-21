//
// Created by Teddy BLANCO on 2023-04-20.
//

#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include "colors.hpp"

#define DEBUG 1
#define FUNCTION 1

class Log {
public:

	static void logToConsole(std::string const & str) {
		if (DEBUG)
			std::cout << BLUE << "[DEBUG]    " << RESET << str << std::endl;
	}

	static void logFunction(std::string const & str) {
		if (FUNCTION)
			std::cout << MAGENTA << "[FUNCTION] " << str << std::endl;
	}
};

#endif //LOG_HPP
