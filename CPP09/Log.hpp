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

	template<typename map_key, typename map_val>
	static void logMap(std::map<map_key, map_val> const & map) {
		if (DEBUG) {
			std::cout << BLUE << "[DEBUG]    " << RESET << "Map content:" << std::endl;
			for (typename std::map<map_key, map_val>::const_iterator it = map.begin(); it != map.end(); ++it) {
				std::cout << BLUE << "[DEBUG]    " << RESET << it->first << " => " << it->second << std::endl;
			}
		}
	}
};

#endif //LOG_HPP
